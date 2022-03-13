//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_COPY_EXAMPLE_H
#define CPPLANGUAGEFEATURES_COPY_EXAMPLE_H
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>

namespace CopyExample {
    using namespace std;

    void main() {
        list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        // copy the elements of coll1 into coll2 by appending them
        vector<int> coll2;
        copy(coll1.cbegin(), coll1.cend(),    // source
             back_inserter(coll2));           // destination

        // copy the elements of coll1 into coll3 by inserting them at the front
        // - reverses the order of the elements
        deque<int> coll3;
        copy(coll1.cbegin(), coll1.cend(),    // source
             front_inserter(coll3));          // destination

        // copy elements of coll1 into coll4
        // - only inserter that works for associative collections
        set<int> coll4;
        copy(coll1.cbegin(), coll1.cend(),    // source
             inserter(coll4, coll4.begin()));  // destination
    }
}
#endif //CPPLANGUAGEFEATURES_COPY_EXAMPLE_H
