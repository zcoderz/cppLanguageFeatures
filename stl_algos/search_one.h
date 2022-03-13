//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_SEARCH_ONE_H
#define CPPLANGUAGEFEATURES_SEARCH_ONE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <deque>
#include <functional>  // for the searchers
#include <execution>   // for the execution policy
#include "../utils/helper.h"
/**
 * bm(): 1.95531 2.28393 1.93439 1.94366 1.90328 ms
  avg: 2.00411ms

bmh(): 580.578 776.62 581.926 579.109 581.48 ms
  avg: 619.943ms

find(): 7.12926 7.17299 7.16063 7.2092 7.12378 ms
  avg: 7.15917ms

par search(): 1943.91 1948.15 1945.79 1950.17 1944.28 ms
  avg: 1946.46ms

search(): 2060.05 2059.79 2059.93 2057.71 2056.48 ms
  avg: 2058.79ms

search(bm): 8.41924 8.40586 8.37038 8.3897 8.54153 ms
  avg: 8.42534ms

search(bmh): 580.189 636.805 579.656 579.314 581.953 ms
  avg: 591.584ms

search(def): 2644.72 2644.18 2642.31 2644.05 2648.66 ms
  avg: 2644.79ms

 Given above bm pre compiled is fastest, followed by find and then bm dynamic
 BM trades space for performance. Per above its performance is 4x standard find which is the next best

 https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm

Process finished with exit code 0
 */

namespace SearchExample {
    using namespace std;

    class SearchOne {
        template<typename T>
        static double diff(const T &t0, const T &t1) {
            return std::chrono::duration<double, std::milli>(t1 - t0).count();
        }

    public:

        static void testMe() {
            // command-line argument to init the maximum sequence of equal characters:
            int max = 1000;

            // create a very big string:
            //  a b c d e ... z aa bb cc dd ee ...
            std::string text;
            text.reserve(max * max * 30);
            for (int i{1}; i <= max; ++i) {
                for (char c{'a'}; c <= 'z'; ++c) {
                    for (int j{1}; j <= i; ++j) {
                        text.push_back(c);
                    }
                }
            }

            // init the substring we search for (max times 'k'):
            std::string substr(max, 'k');
            std::cout << "search substring of " << max
                      << " chars in string with " << text.size() << " chars\n";

            // init searchers for reuse:
            std::boyer_moore_searcher bm{substr.begin(), substr.end()};
            std::boyer_moore_horspool_searcher bmh{substr.begin(), substr.end()};

            // map to store measurements under a specific name:
            std::map<std::string, std::vector<double>> durs;

            // multiple measurements to make numbers mature:
            for (int i = 0; i < 5; ++i) {
                std::chrono::steady_clock::time_point t0, t1;
                std::string::iterator pos;

                // string member find():
                t0 = std::chrono::steady_clock::now();
                auto idx = text.find(substr);
                t1 = std::chrono::steady_clock::now();
                durs["find()"].push_back(diff(t0, t1));
                std::cout << "idx: " << idx << '\n';

                // search() algorithm:
                t0 = std::chrono::steady_clock::now();
                pos = std::search(text.begin(), text.end(),
                                  substr.begin(), substr.end());
                t1 = std::chrono::steady_clock::now();
                durs["search()"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';

                // parallel search() algorithm:

                t0 = std::chrono::steady_clock::now();
                pos = std::search(std::execution::par,
                                  text.begin(), text.end(),
                                  substr.begin(), substr.end());
                t1 = std::chrono::steady_clock::now();
                durs["par search()"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';


                // default_searcher:
                t0 = std::chrono::steady_clock::now();
                pos = std::search(text.begin(), text.end(),
                                  std::default_searcher(substr.begin(), substr.end()));
                t1 = std::chrono::steady_clock::now();
                durs["search(def)"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';

                // boyer_moore_searcher:
                t0 = std::chrono::steady_clock::now();
                pos = std::search(text.begin(), text.end(),
                                  std::boyer_moore_searcher(substr.begin(), substr.end()));
                t1 = std::chrono::steady_clock::now();
                durs["search(bm)"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';

                // boyer_moore_horspool_searcher:
                t0 = std::chrono::steady_clock::now();
                pos = std::search(text.begin(), text.end(),
                                  std::boyer_moore_horspool_searcher(substr.begin(), substr.end()));
                t1 = std::chrono::steady_clock::now();
                durs["search(bmh)"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';

                // reused boyer_moore_searcher:
                t0 = std::chrono::steady_clock::now();
                pos = bm(text.begin(), text.end()).first;
                t1 = std::chrono::steady_clock::now();
                durs["bm()"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';

                // reused boyer_moore_horspool_searcher:
                t0 = std::chrono::steady_clock::now();
                pos = bmh(text.begin(), text.end()).first;
                t1 = std::chrono::steady_clock::now();
                durs["bmh()"].push_back(diff(t0, t1));
                std::cout << "idx: " << pos - text.begin() << '\n';
            }

            // print measurements:
            for (const auto &elem: durs) {
                std::cout << "\n" << elem.first << ": ";
                double avg = 0;
                for (const auto &val: elem.second) {
                    std::cout << val << " ";
                    avg += val;
                }
                std::cout << "ms\n";
                std::cout << "  avg: " << avg / elem.second.size() << "ms\n";
            }
        }

        void searchExampleTwo() {
            deque<int> coll;
            list<int> subcoll;

            INSERT_ELEMENTS(coll, 1, 7);
            INSERT_ELEMENTS(coll, 1, 7);
            INSERT_ELEMENTS(subcoll, 3, 6);

            PRINT_ELEMENTS(coll, "coll:    ");
            PRINT_ELEMENTS(subcoll, "subcoll: ");

            // search first occurrence of subcoll in coll
            deque<int>::iterator pos;
            pos = search(coll.begin(), coll.end(),         // range
                         subcoll.begin(), subcoll.end());  // subrange

            // loop while subcoll found as subrange of coll
            while (pos != coll.end()) {
                // print position of first element
                cout << "subcoll found starting with element "
                     << distance(coll.begin(), pos) + 1
                     << endl;

                // search next occurrence of subcoll
                ++pos;
                pos = search(pos, coll.end(),                  // range
                             subcoll.begin(), subcoll.end());  // subrange
            }
        }
    };
}

#endif //CPPLANGUAGEFEATURES_SEARCH_ONE_H
