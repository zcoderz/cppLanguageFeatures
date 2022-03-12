//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_SORT_EXAMPLE_H
#define CPPLANGUAGEFEATURES_SORT_EXAMPLE_H
#include <algorithm>
#include <deque>
#include <string>
#include <iostream>

namespace Sort {
    using namespace std;
/* class Person
 */
    class Person {
    private:
        string fn;    // first name
        string ln;    // last name
    public:
        Person() {
        }

        Person(const string &f, const string &n)
                : fn(f), ln(n) {
        }

        string firstname() const;

        string lastname() const;
        // ...
    };

    inline string Person::firstname() const {
        return fn;
    }

    inline string Person::lastname() const {
        return ln;
    }

    ostream &operator<<(ostream &s, const Person &p) {
        s << "[" << p.firstname() << " " << p.lastname() << "]";
        return s;
    }


/* binary function predicate:
 * - returns whether a person is less than another person
 */
    bool personSortCriterion(const Person &p1, const Person &p2) {
        /* a person is less than another person
         * - if the last name is less
         * - if the last name is equal and the first name is less
         */
        return p1.lastname() < p2.lastname() ||
               (p1.lastname() == p2.lastname() &&
                p1.firstname() < p2.firstname());
    }

    void main() {
        // create some persons
        Person p1("nicolai", "josuttis");
        Person p2("ulli", "josuttis");
        Person p3("anica", "josuttis");
        Person p4("lucas", "josuttis");
        Person p5("lucas", "otto");
        Person p6("lucas", "arm");
        Person p7("anica", "holle");

        // insert person into collection coll
        deque <Person> coll;
        coll.push_back(p1);
        coll.push_back(p2);
        coll.push_back(p3);
        coll.push_back(p4);
        coll.push_back(p5);
        coll.push_back(p6);
        coll.push_back(p7);

        // print elements
        cout << "deque before sort():" << endl;
        deque<Person>::iterator pos;
        for (pos = coll.begin(); pos != coll.end(); ++pos) {
            cout << *pos << endl;
        }

        // sort elements
        sort(coll.begin(), coll.end(),    // range
             personSortCriterion);       // sort criterion

//        sort(coll.begin(),coll.end(),                // range
//             [] (const Person& p1, const Person& p2) { // sort criterion
//                 return p1.lastname()<p2.lastname() ||
//                        (p1.lastname()==p2.lastname() &&
//                         p1.firstname()<p2.firstname());
//             });

        // print elements
        cout << "deque after sort():" << endl;
        for (pos = coll.begin(); pos != coll.end(); ++pos) {
            cout << *pos << endl;
        }
    }
}
#endif //CPPLANGUAGEFEATURES_SORT_EXAMPLE_H
