//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_TRANSFORM_EXAMPLE_H
#define CPPLANGUAGEFEATURES_TRANSFORM_EXAMPLE_H
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "../utils/helper.h"


namespace Transform {

    int square(int value) {
        return value * value;
    }

    void main() {
        std::set<int> coll1;
        std::vector<int> coll2;

        // insert elements from 1 to 9 into coll1
        for (int i = 1; i <= 9; ++i) {
            coll1.insert(i);
        }
        PRINT_ELEMENTS(coll1, "initialized: ");

        // transform each element from coll1 to coll2
        // - square transformed values
        std::transform(coll1.cbegin(), coll1.cend(),  // source
                       std::back_inserter(coll2),    // destination
                       square);                      // operation

        PRINT_ELEMENTS(coll2, "squared:     ");
    }
}
#endif //CPPLANGUAGEFEATURES_TRANSFORM_EXAMPLE_H
