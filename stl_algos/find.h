/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include "../library/helper.h"

using namespace std;

namespace FindExample {


    void mainOne() {
        list<int> coll;

        INSERT_ELEMENTS(coll, 1, 9);
        INSERT_ELEMENTS(coll, 1, 9);

        PRINT_ELEMENTS(coll, "coll: ");

        // find first element with value 4
        list<int>::iterator pos1;
        pos1 = find(coll.begin(), coll.end(),    // range
                    4);                          // value

        // find second element with value 4
        // - note: continue the search behind the first 4 (if any)
        list<int>::iterator pos2;
        if (pos1 != coll.end()) {
            pos2 = find(++pos1, coll.end(),      // range
                        4);                      // value
        }

        // print all elements from first to second 4 (both included)
        // - note: now we need the position of the first 4 again (if any)
        if (pos1 != coll.end() && pos2 != coll.end()) {
            copy(--pos1, ++pos2,
                 ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }

    void main2()
    {
        vector<int> coll;
        vector<int>::iterator pos;

        INSERT_ELEMENTS(coll,1,9);
        PRINT_ELEMENTS(coll,"coll: ");

        //stick with lambdas instead of bind
        // find first element greater than 3
        //pos = find_if (coll.begin(), coll.end(),    // range
        //               bind(greater<int>(),_1,3));  // criterion


        // find first element divisible by 3
        pos = find_if (coll.begin(), coll.end(),
                       [](int elem){
                           return elem%3==0;
                       });

        // print its position
        cout << "the "
             << distance(coll.begin(),pos) + 1
             << ". element is the first divisible by 3" << endl;

    }
}