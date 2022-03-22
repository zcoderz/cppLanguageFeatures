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

#ifndef RANGE_SORT_H
#define RANGE_SORT_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace RangeSort {


    void print(const auto &coll) {
        for (const auto &elem: coll) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    void main(int argc, char **argv) {
        std::vector<std::string> coll{"Rio", "Tokyo", "New York", "Berlin"};

        std::ranges::sort(coll);     // sort elements
        std::ranges::sort(coll[0]);  // sort character in first element
        print(coll);

        int arr[] = {42, 0, 8, 15, 7};
        std::ranges::sort(arr);      // sort values in array
        print(arr);
    }
}
#endif