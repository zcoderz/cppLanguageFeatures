//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_REMOVE_H
#define CPPLANGUAGEFEATURES_REMOVE_H

#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>


namespace Remove {
    using namespace std;

    void eraseRemove() {
        cout << "Erase remove -3" << endl;
        list<int> coll;

        // insert elements from 6 to 1 and 1 to 6
        for (int i = 1; i <= 6; ++i) {
            coll.push_front(i);
            coll.push_back(i);
        }

        cout << "pre: ";
        copy(coll.cbegin(), coll.cend(),         // source
             ostream_iterator<int>(cout, " "));   // destination
        cout << endl;

        // remove all elements with value 3 (poor performance)
        coll.erase(remove(coll.begin(), coll.end(),
                          3),
                   coll.end());

        // remove all elements with value 4 (good performance)
        coll.remove(4);
        cout << "post: ";
        copy(coll.cbegin(), coll.cend(),         // source
             ostream_iterator<int>(cout, " "));   // destination
        cout << endl;
    }

    void onlyRemove() {
        cout << "Only remove -3. size doesnt change elements at end have unspecified value" << endl;
        list<int> coll;

        // insert elements from 6 to 1 and 1 to 6
        for (int i = 1; i <= 6; ++i) {
            coll.push_front(i);
            coll.push_back(i);
        }

        // print all elements of the collection
        cout << "pre:  ";
        copy(coll.cbegin(), coll.cend(),         // source
             ostream_iterator<int>(cout, " "));   // destination
        cout << endl;

        // remove all elements with value 3
        remove(coll.begin(), coll.end(),         // range
               3);                               // value

        // print all elements of the collection
        cout << "post: ";
        copy(coll.cbegin(), coll.cend(),         // source
             ostream_iterator<int>(cout, " "));   // destination
        cout << endl;
    }

    void testMe() {
        onlyRemove();
        eraseRemove();
    }
}
#endif //CPPLANGUAGEFEATURES_REMOVE_H
