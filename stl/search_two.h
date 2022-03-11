//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_SEARCH_TWO_H
#define CPPLANGUAGEFEATURES_SEARCH_TWO_H
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <chrono>
#include <functional>  // for the searchers
#include <execution>  // for the execution policy


/**
 * Can use search to find an index of a smaller collection inside a bigger collection
 * bm(): 5.91562 5.8378 5.98913 5.87827 6.02625 ms
  avg: 5.92941ms

bmh(): 2689.55 2688.58 2688.94 2684.95 2689.64 ms
  avg: 2688.33ms

par search(): 1783.19 1778.63 1783.79 1781.16 1783.28 ms
  avg: 1782.01ms

search(): 2089.47 2083.94 2086.43 2087.24 2084.04 ms
  avg: 2086.22ms

search(bm): 48.0194 47.3285 47.5338 47.8907 48.2694 ms
  avg: 47.8083ms

search(bmh): 2694.31 2697.26 2693.28 2692.26 2686.88 ms
  avg: 2692.8ms

search(def): 2663.24 2657.2 2652.58 2653.14 2656.67 ms
  avg: 2656.57ms

Process finished with exit code 0

 */
class SearchTwo {

    template <typename T>
    static double diff(const T& t0, const T& t1)
    {
        return std::chrono::duration<double,std::milli>(t1 - t0).count();
    }

public:
    static void testMe()
    {
        // command-line argument to init the maximum sequence of equal characters:
        int max = 1000;

        // create a very big vector:
        //  0 1 2 3 4 ... 9 00 11 22 33 44 ...
        std::vector<int> coll;
        coll.reserve(max*max*10);
        for (int i{1}; i<=max; ++i) {
            for (int v{0}; v<=9; ++v) {
                for (int j{1}; j<=i; ++j) {
                    coll.push_back(v);
                }
            }
        }

        // init the subsequence we search for (max times '4'):
        std::deque<int> sub(max, 4);
        std::cout << "search sequence of " << max
                  << " ints in vector with " << coll.size() << " ints\n";

        // init searchers for reuse:
        std::boyer_moore_searcher bm{sub.begin(), sub.end()};
        std::boyer_moore_horspool_searcher bmh{sub.begin(), sub.end()};

        // map to store measurements under a specific name:
        std::map<std::string, std::vector<double>> durs;

        // multiple measurements to make numbers mature:
        for (int i=0; i<5; ++i) {
            std::chrono::steady_clock::time_point t0, t1;
            std::vector<int>::iterator pos;



            // search() algorithm:
            t0 = std::chrono::steady_clock::now();
            pos = std::search(coll.begin(), coll.end(),
                              sub.begin(), sub.end());
            t1 = std::chrono::steady_clock::now();
            durs["search()"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';

            // parallel search() algorithm:

            t0 = std::chrono::steady_clock::now();
            pos = std::search(std::execution::par,
                              coll.begin(), coll.end(),
                              sub.begin(), sub.end());
            t1 = std::chrono::steady_clock::now();
            durs["par search()"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';


            // default_searcher:
            t0 = std::chrono::steady_clock::now();
            pos = std::search(coll.begin(), coll.end(),
                              std::default_searcher(sub.begin(), sub.end()));
            t1 = std::chrono::steady_clock::now();
            durs["search(def)"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';

            // boyer_moore_searcher:
            t0 = std::chrono::steady_clock::now();
            pos = std::search(coll.begin(), coll.end(),
                              std::boyer_moore_searcher(sub.begin(), sub.end()));
            t1 = std::chrono::steady_clock::now();
            durs["search(bm)"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';

            // boyer_moore_horspool_searcher:
            t0 = std::chrono::steady_clock::now();
            pos = std::search(coll.begin(), coll.end(),
                              std::boyer_moore_horspool_searcher(sub.begin(), sub.end()));
            t1 = std::chrono::steady_clock::now();
            durs["search(bmh)"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';

            // reused boyer_moore_searcher:
            t0 = std::chrono::steady_clock::now();
            pos = bm(coll.begin(), coll.end()).first;
            t1 = std::chrono::steady_clock::now();
            durs["bm()"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';

            // reused boyer_moore_horspool_searcher:
            t0 = std::chrono::steady_clock::now();
            pos = bmh(coll.begin(), coll.end()).first;
            t1 = std::chrono::steady_clock::now();
            durs["bmh()"].push_back(diff(t0, t1));
            std::cout << "idx: " << pos - coll.begin() << '\n';
        }

        // print measurements:
        for (const auto& elem : durs) {
            std::cout << "\n" << elem.first << ": ";
            double avg = 0;
            for (const auto& val : elem.second) {
                std::cout << val << " ";
                avg += val;
            }
            std::cout << "ms\n";
            std::cout << "  avg: " << avg / elem.second.size() << "ms\n";
        }
    }
};

#endif //CPPLANGUAGEFEATURES_SEARCH_TWO_H
