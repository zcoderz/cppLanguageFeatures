//
// Created by usman on 3/7/22.
//

#ifndef CPPLANGUAGEFEATURES_NO_EXCEPT_EXAMPLE_H
#define CPPLANGUAGEFEATURES_NO_EXCEPT_EXAMPLE_H

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class Person {
private:
    std::string name;
public:
    Person(const char* n)
            : name{n} {
    }

    std::string getName() const {
        return name;
    }

    // print out when we copy or move:
    Person(const Person& p)
            : name{p.name} {
        std::cout << "COPY " << name << '\n';
    }
//    Person(Person&& p) = default;
    /**
     * If you specify noexcept in the move constructor , the realloc in a container will use the move constructor
     * instead of the copy constructor
     * @param p
     */
//    Person(Person&& p) noexcept
//            : name{std::move(p.name)} {
//        try {
//            std::cout << "MOVE " << name << '\n';
//        } catch (...) {}
//    }

    /**
     * Recommended way is to add a noexcept check in method signature to ensure that the logic is indeed noexcept
     * compiler will execute the checks at compile time to analyze
     * @param p
     */
    Person(Person&& p) noexcept  ( (std::is_nothrow_move_constructible_v<std::string>))
                                   //&& noexcept(std::cout << name))
            : name{std::move(p.name)} {
        try {
            std::cout << "MOVE " << name << '\n';
        } catch (...) {}
    }
    //...
    static void  testMain()
    {
        std::vector<Person> coll{"Wolfgang Amadeus Mozart",
                                 "Johann Sebastian Bach",
                                 "Ludwig van Beethoven"};
        std::cout << "capacity: " << coll.capacity() << '\n';
        coll.emplace_back("Pjotr Iljitsch Tschaikowski");
    }
};

#endif //CPPLANGUAGEFEATURES_NO_EXCEPT_EXAMPLE_H
