//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_BITSET_EXAMPLE_H
#define CPPLANGUAGEFEATURES_BITSET_EXAMPLE_H

#include <bitset>
#include <iostream>

class BitsetExample{
public:
    static void testMe()
    {
        std::bitset<4> bset1(9); // bset1 contains 1001
        std::bitset<4> bset2(3); // bset2 contains 0011

        // comparison operator
        std::cout << (bset1 == bset2) << std::endl; // false 0
        std::cout << (bset1 != bset2) << std::endl; // true  1

        // bitwise operation and assignment
        std::cout << (bset1 ^= bset2) << std::endl; // 1010
        std::cout << (bset1 &= bset2) << std::endl; // 0010
        std::cout << (bset1 |= bset2) << std::endl; // 0011

        // left and right shifting
        std::cout << (bset1 <<= 2) << std::endl; // 1100
        std::cout << (bset1 >>= 1) << std::endl; // 0110

        // not operator
        std::cout << (~bset2) << std::endl; // 1100

        // bitwise operator
        std::cout << (bset1 & bset2) << std::endl; // 0010
        std::cout << (bset1 | bset2) << std::endl; // 0111
        std::cout << (bset1 ^ bset2) << std::endl; // 0101
    }
};

#endif //CPPLANGUAGEFEATURES_BITSET_EXAMPLE_H
