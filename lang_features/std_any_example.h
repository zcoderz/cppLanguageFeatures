//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_STD_ANY_EXAMPLE_H
#define CPPLANGUAGEFEATURES_STD_ANY_EXAMPLE_H

#include <vector>
#include <any>
#include <string>
#include <iostream>

class StdAny {
public:
    static void testMe() {
        std::vector<std::any> theVec = {1,1.1, 2.23, "abcd char *", std::string("the str")};

        for (const auto & a: theVec) {
           std::cout << "type :" << a.type().name() << std::endl;
           if (a.type() == typeid(const char *)) {
               std::cout << "val :" << std::any_cast<const char *>(a) << std::endl;
           } else if (a.type() == typeid(std::string)) {
               std::cout << "val :" << std::any_cast<std::string>(a) << std::endl;
           } else if (a.type() == typeid(int)) {
               std::cout << "val :" << std::any_cast<int>(a) << std::endl;
           } else if (a.type() == typeid(double)) {
               std::cout << "val :" << std::any_cast<double>(a) << std::endl;
           } else {
               std::cout << "no conversion" << std::endl;
           }
            std::cout << "-------------------------------------------"  << std::endl;
        }
    }
};

#endif //CPPLANGUAGEFEATURES_STD_ANY_EXAMPLE_H
