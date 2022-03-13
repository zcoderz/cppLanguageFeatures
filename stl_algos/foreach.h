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

namespace ForEachExample {
    using namespace std;

// function object to process the mean value
    class MeanValue {
    private:
        long num;    // number of elements
        long sum;    // sum of all element values
    public:
        // constructor
        MeanValue() : num(0), sum(0) {
        }

        // function call
        // - process one more element of the sequence
        void operator()(int elem) {
            num++;          // increment count
            sum += elem;    // add value
        }

        // return mean value (implicit type conversion)
        operator double() {
            return static_cast<double>(sum) / static_cast<double>(num);
        }
    };

    void main() {
        vector<int> coll;

        INSERT_ELEMENTS(coll, 1, 8);

        // process and print mean value
        double mv = for_each(coll.begin(), coll.end(),  // range
                             MeanValue());              // operation
        cout << "mean value: " << mv << endl;

        coll.clear();
        INSERT_ELEMENTS(coll,1,9);

        // add value of first element to each element
        for_each (coll.begin(), coll.end(),       // range
                  [=](int& elem){                 // operation
                      elem += *coll.begin();
                  });
        PRINT_ELEMENTS(coll);
    }

}