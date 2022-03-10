//
// Created by usman on 3/4/22.
//

#ifndef CPPLANGUAGEFEATURES_FUNCTION_OBJECT_H
#define CPPLANGUAGEFEATURES_FUNCTION_OBJECT_H
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class LessThan {
    const T _val;
public:
    LessThan(const T & v_) :_val(v_) {}
    bool operator() (const T & comp) {
        return comp < _val;
    }
};

void testLessThanFunctionObject() {
    std::vector<int> vals = {1,2,3,4,5,6,7};
    //count number of elements in vector that are less than 5!
    long val = std::count_if(vals.begin(), vals.end(), LessThan(5));
    std::cout << val << std::endl;
}
#endif //CPPLANGUAGEFEATURES_FUNCTION_OBJECT_H
