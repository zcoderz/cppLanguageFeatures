//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_LAMDA_EXAMPLE_H
#define CPPLANGUAGEFEATURES_LAMDA_EXAMPLE_H

#include <algorithm>
#include <deque>
#include <iostream>

namespace LambdaExampleOne {
    using namespace std;
    void main() {
        deque<int> coll = {1, 3, 19, 5, 13, 7, 11, 2, 17};

        int x = 5;
        int y = 12;
        auto pos = find_if(coll.cbegin(), coll.cend(),  // range
                           [=](int i) {                 // search criterion
                               return i > x && i < y;
                           });
        cout << "first elem >5 and <12: " << *pos << endl;
    }
}
#endif //CPPLANGUAGEFEATURES_LAMDA_EXAMPLE_H
