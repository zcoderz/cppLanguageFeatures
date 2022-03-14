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
#include <iostream>
#include <set>

namespace SetRangeExample {
    using namespace std;

    void main() {
        multiset<int> c;

        c.insert(1);
        c.insert(2);
        c.insert(3);
        c.insert(3);
        c.insert(4);
        c.insert(5);
        c.insert(6);

        cout << "lower_bound(3): --location-- " << distance(c.begin(), c.lower_bound(3)) + 1 << endl;
        cout << "upper_bound(3): --location-- " << distance(c.begin(),c.upper_bound(3)) + 1 << endl;
        cout << "equal_range(3): " << *c.equal_range(3).first << " "
             << *c.equal_range(3).second << endl;
        cout << endl;
        cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
        cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
        cout << "equal_range(5): " << *c.equal_range(5).first << " "
             << *c.equal_range(5).second << endl;
    }
}