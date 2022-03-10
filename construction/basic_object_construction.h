//
// Created by usman on 3/4/22.
//

#ifndef CPPLANGUAGEFEATURES_BASIC_OBJECT_CONSTRUCTION_H
#define CPPLANGUAGEFEATURES_BASIC_OBJECT_CONSTRUCTION_H

#include <string>
#include <vector>
#include <iostream>

class BasicObjectConstruction {
public:
    BasicObjectConstruction() = delete;
    /**
     * Do not allow implicit conversion from int to vector
     * @param sz
     */
    explicit BasicObjectConstruction(const int sz) {
        std::cout << "Calling constructor with parameter " << sz << std::endl;
        vals.reserve(sz);
    }

    explicit BasicObjectConstruction(BasicObjectConstruction & other) {
        vals = other.vals;
        std::cout << "Calling copy constructor " << std::endl;
    }

    BasicObjectConstruction(BasicObjectConstruction && other) : vals(std::move(other.vals))  {
        std::cout << "Calling move constructor "  << std::endl;
    }

    //the class has no assignment operator
    BasicObjectConstruction& operator=(const BasicObjectConstruction &) = delete;

    //the class has a move assignment operator
    BasicObjectConstruction& operator=(BasicObjectConstruction && other) {
        vals = std::move(other.vals);
        std::cout << "Calling move assignment operator " <<  std::endl;
        return *this;
    }

    ~BasicObjectConstruction() {
    }

    static void testMe() {
        BasicObjectConstruction basic = BasicObjectConstruction(2);
        //BasicObjectConstruction basic2 = basic; wont compile because assignment operator is deleted and copy constructor is marked explicit
        BasicObjectConstruction basic2 = std::move(basic); //move constructor
        BasicObjectConstruction basic3 = test2(BasicObjectConstruction(3)); //calls move constructor to move the rvalue from function into the basic3 object being constructor
        basic = std::move(basic3); //calls move assignment operator
        basic = BasicObjectConstruction(2);
        basic2 = BasicObjectConstruction(2);
        basic.vals.push_back(1); basic.vals.push_back(2);
        basic2.vals.push_back(1); basic2.vals.push_back(3);
        if (basic == basic2) {
            std::cout << "The two objects are equal" << std::endl;
        } else {
            std::cout << "The two objects are not equal" << std::endl;
        }
        basic << std::cout; //calls the operator on the member function
        std::cout << basic; //calls the non-member operator

    }

    std::ostream& operator<<(std::ostream& os)
    {
        os << "calling member ostream operator " << std::endl;
        for (int v: vals) {
            os << v << ", ";
        }
        os << std::endl;
        return os;
    }

    static BasicObjectConstruction test2(BasicObjectConstruction obj) {
        return obj;
    }
private:
    std::vector<int> vals;
    //you have to define the
    friend bool  operator==(const BasicObjectConstruction & left, const BasicObjectConstruction & right);
    friend std::ostream& operator<<(std::ostream& os, const BasicObjectConstruction& myObj);
};

bool  operator==(const BasicObjectConstruction & left, const BasicObjectConstruction & right) {
    if (left.vals.size() != right.vals.size()) {
        return false;
    }
    for (int i =0; i < left.vals.size(); i++) {
        if (left.vals[i] != right.vals[i]) return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const BasicObjectConstruction& myObj) {
    os << "calling non member ostream operator " << std::endl;
    for (int v: myObj.vals) {
        os << v << ", ";
    }
    os << std::endl;
    return os;
}

#endif //CPPLANGUAGEFEATURES_BASIC_OBJECT_CONSTRUCTION_H
