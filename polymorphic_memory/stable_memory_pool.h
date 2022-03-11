//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_STABLE_MEMORY_POOL_H
#define CPPLANGUAGEFEATURES_STABLE_MEMORY_POOL_H
#include "tracker.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory_resource>

class StableMemoryPool {
public:
    static void testMe()
    {
        {
            // track allocating chunks of memory (starting with 10k) without deallocating:
            Tracker track1{"keeppool:"};
            //this pool is allocated across all instances of the below loop. hence the memory allocations in this pool
            //are stable.
            std::pmr::monotonic_buffer_resource keeppool{10000, &track1};
            {
                Tracker track2{"  syncpool:", &keeppool};
                //this pool utilizes the keep-pool above and hence has stable memory allocations across the iterations
                //as memory gets released back to the pool at end of the iteration
                std::pmr::synchronized_pool_resource pool{&track2};

                for (int j=0; j < 100; ++j) {
                    std::pmr::vector<std::pmr::string> coll{&pool};
                    coll.reserve(100);
                    for (int i=0; i < 100; ++i) {
                        coll.emplace_back("just a non-SSO string");
                    }
                    if (j==2) std::cout << "--- third iteration done\n";
                } // deallocations are given back to pool, but not deallocated
                // so far nothing was allocated
                std::cout << "--- leave scope of pool\n";
            }
            std::cout << "--- leave scope of keeppool\n";
        } // deallocates all allocated memory
    }
};
#endif //CPPLANGUAGEFEATURES_STABLE_MEMORY_POOL_H
