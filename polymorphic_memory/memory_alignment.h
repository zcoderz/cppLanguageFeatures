//
// Created by usman on 3/11/22.
//

#ifndef CPPLANGUAGEFEATURES_MEMORY_ALIGNMENT_H
#define CPPLANGUAGEFEATURES_MEMORY_ALIGNMENT_H
#include <string>
#include <iostream>
#include <new>
class MemoryAlignment {

    struct alignas(32) MyType32 {
        int i;
        char c;
        std::string s[4];
    };

public:
    static void testMe()
    {
        auto p = new MyType32;  // allocates 32-byte aligned memory since C++17
        //...
        delete p;
    }
};
#endif //CPPLANGUAGEFEATURES_MEMORY_ALIGNMENT_H
