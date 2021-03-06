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

namespace PermutationExample {
    using namespace std;

    int main() {
        vector<int> coll;
        INSERT_ELEMENTS(coll, 1, 3);
        PRINT_ELEMENTS(coll, "on entry:  ");

        // permute elements until they are sorted
        // - runs through all permutations because the elements are sorted now
        while (next_permutation(coll.begin(), coll.end())) {
            PRINT_ELEMENTS(coll, " ");
        }
        PRINT_ELEMENTS(coll, "afterward: ");

        // permute until descending sorted
        // - this is the next permutation after ascending sorting
        // - so the loop ends immediately
        while (prev_permutation(coll.begin(), coll.end())) {
            PRINT_ELEMENTS(coll, " ");
        }
        PRINT_ELEMENTS(coll, "now:       ");

        // permute elements until they are sorted in descending order
        // - runs through all permutations because the elements are sorted in descending order now
        while (prev_permutation(coll.begin(), coll.end())) {
            PRINT_ELEMENTS(coll, " ");
        }
        PRINT_ELEMENTS(coll, "afterward: ");
    }
}