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
    using namespace std;
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

    void exampleTwo()
    {
        vector<int> coll1;
        list<int> coll2;

        INSERT_ELEMENTS(coll1,1,9);
        PRINT_ELEMENTS(coll1,"coll1:   ");

        // square each element
        transform (coll1.cbegin(), coll1.cend(),     // first source range
                   coll1.cbegin(),                   // second source range
                   coll1.begin(),                    // destination range
                   multiplies<int>());               // operation
        PRINT_ELEMENTS(coll1,"squared: ");

        // add each element traversed forward with each element traversed backward
        // and insert result into coll2
        transform (coll1.cbegin(), coll1.cend(),     // first source range
                   coll1.crbegin(),                  // second source range
                   back_inserter(coll2),             // destination range
                   plus<int>());                     // operation
        PRINT_ELEMENTS(coll2,"coll2:   ");

        // print differences of two corresponding elements
        cout << "diff:    ";
        transform (coll1.cbegin(), coll1.cend(),     // first source range
                   coll2.cbegin(),                   // second source range
                   ostream_iterator<int>(cout, " "), // destination range
                   minus<int>());                    // operation
        cout << endl;
    }
}
#endif //CPPLANGUAGEFEATURES_TRANSFORM_EXAMPLE_H
