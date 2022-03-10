//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_COMPILE_TIME_IF_H
#define CPPLANGUAGEFEATURES_COMPILE_TIME_IF_H

#include <string>
#include <iostream>

class CompileTimeIf {
    template <typename T>
    static std::string asString(T x)
    {
        if constexpr(std::is_same_v<T, std::string>) {
            return x;                  // statement invalid if no conversion to string
        }
        else if constexpr(std::is_arithmetic_v<T>) {
            return std::to_string(x);  // statement invalid if x is not numeric
        }
        else {
            return std::string(x);     // statement invalid if no conversion to string
        }
    }

public:
    static void testMe() {
        //compile time conversions executed here
        std::string val = asString(2.1111212);
        std::string strTemp = "abcd";
        std:std::cout << "Val of STR-TMP is " << strTemp << ", val converted to string is : " << val << std::endl;
    }
};
#endif //CPPLANGUAGEFEATURES_COMPILE_TIME_IF_H
