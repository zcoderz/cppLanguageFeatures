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

namespace CopyExample {
    using namespace std;

    void main() {
        vector<string> coll1 = {"Hello", "this", "is", "an", "example"};
        list<string> coll2;

        // copy elements of coll1 into coll2
        // - use back inserter to insert instead of overwrite
        copy(coll1.cbegin(), coll1.cend(),         // source range
             back_inserter(coll2));                // destination range

        // print elements of coll2
        // - copy elements to cout using an ostream iterator
        copy(coll2.cbegin(), coll2.cend(),         // source range
             ostream_iterator<string>(cout, " "));  // destination range
        cout << endl;

        // copy elements of coll1 into coll2 in reverse order
        // - now overwriting
        copy(coll1.crbegin(), coll1.crend(),       // source range
             coll2.begin());                       // destination range

        // print elements of coll2 again
        copy(coll2.cbegin(), coll2.cend(),         // source range
             ostream_iterator<string>(cout, " "));  // destination range
        cout << endl;
    }
}