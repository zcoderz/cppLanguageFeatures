//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_INLINE_H
#define CPPLANGUAGEFEATURES_INLINE_H

#include <string>
#include <iostream>

class InLineTest {
public:
    inline static std::string gName = "global";            // unique in program
    inline static thread_local std::string tName = "tls";  // unique per thread
    std::string lName = "local";                           // for each object
    //...
    void print(const std::string& msg) const {
        std::cout << msg << '\n';
        std::cout << "- gName: " << gName << '\n';
        std::cout << "- tName: " << tName << '\n';
        std::cout << "- lName: " << lName << '\n';
    }
    static void foo();
    static void testMe();

};

//program wide global variables can be defined now in header file via marking them as inline
//these variables can now be compiled across various translation units
inline thread_local InLineTest myThreadData;

#endif //CPPLANGUAGEFEATURES_INLINE_H
