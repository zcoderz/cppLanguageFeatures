//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_FOR_EACH_EXAMPLE_H
#define CPPLANGUAGEFEATURES_FOR_EACH_EXAMPLE_H
#include <vector>
#include <algorithm>
#include <iostream>

namespace ForEachExample {
    using namespace std;

// simple function object that prints the passed argument
    class PrintInt {
    public:
        void operator()(int elem) const {
            cout << elem << ' ';
        }
    };

    void main() {
        vector<int> coll;

        // insert elements from 1 to 9
        for (int i = 1; i <= 9; ++i) {
            coll.push_back(i);
        }

        // print all elements
        for_each(coll.cbegin(), coll.cend(),  // range
                 PrintInt());                 // operation
        cout << endl;
    }
}
#endif //CPPLANGUAGEFEATURES_FOR_EACH_EXAMPLE_H
