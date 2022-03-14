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
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>
#include "buckets.h"

namespace UnorderedMultiMapExample {
    using namespace std;

    int main() {
        // create and initialize an unordered multimap as dictionary
        std::unordered_multimap<string, string> dict = {
                {"day",     "Tag"},
                {"strange", "fremd"},
                {"car",     "Auto"},
                {"smart",   "elegant"},
                {"trait",   "Merkmal"},
                {"strange", "seltsam"}
        };
        printHashTableState(dict);

        // insert some additional values (might cause rehashing)
        dict.insert({{"smart",  "raffiniert"},
                     {"smart",  "klug"},
                     {"clever", "raffiniert"}
                    });
        printHashTableState(dict);

        // modify maximum load factor (might cause rehashing)
        //The load factor is the ratio between the number of elements in the container (its size) and
        //the number of buckets (bucket_count). By default, unordered_map containers have a max_load_factor of 1.0
        dict.max_load_factor(0.7);
        printHashTableState(dict);
    }
}