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
#include <fstream>
#include <memory>

namespace StreamRedirectExample {
    using namespace std;

    void redirect(ostream &);

    void main() {
        cout << "the first row" << endl;

        redirect(cout);

        cout << "the last row" << endl;
    }

    void redirect(ostream &strm) {
        // save output buffer of the stream
        // - use unique pointer with deleter that ensures to restore
        //     the original output buffer at the end of the function
        auto del = [&](streambuf *p) {
            strm.rdbuf(p);
        };
        //unique ptr with a custom delete function that resets the stream redirect buffer
        unique_ptr<streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);

        // redirect ouput into the file redirect.txt
        ofstream file("/tmp/redirect.txt");
        //redirect the file buffer to the stream such that io to stream is redirected into the file
        strm.rdbuf(file.rdbuf());

        file << "one row for the file" << endl;
        strm << "one row for the stream" << endl;
    } // closes file AND its buffer automatically
}