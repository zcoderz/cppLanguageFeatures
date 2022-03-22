//********************************************************
// The following code example is taken from the book
//  C++20 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd20.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************
#ifndef _SENTINEL_TWO_H
#define _SENTINEL_TWO_H
#include <iostream>
#include <algorithm>

namespace SentinelTwo {



    template<auto End>
    struct EndValue {
        bool operator==(auto pos) const {
            return *pos == End;  // end is where iterator points to End
        }
    };

    int main() {
        std::vector coll = {42, 8, 0, 15, 7, -1};  // -1 marks the end

        // define a range the begin of coll and the element 7 as end:
        std::ranges::subrange range{coll.begin(), EndValue<7>{}};

        // sort the elements of this range:
        std::ranges::sort(range);

        // print the elements of the range:
        std::ranges::for_each(range,
                              [](auto val) {
                                  std::cout << ' ' << val;
                              });
        std::cout << '\n';

        // print all elements of coll up to -1:
        std::ranges::for_each(coll.begin(), EndValue<-1>{},
                              [](auto val) {
                                  std::cout << ' ' << val;
                              });
        std::cout << '\n';
    }
}
#endif