//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_PMR_NULL_H
#define CPPLANGUAGEFEATURES_PMR_NULL_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <cstddef>  // for std::byte
#include <memory_resource>

class PMRNull {
public:
    static void testMe() {
        // use memory on the stack without fallback on the heap:
        std::array<std::byte, 200000> buf;
        std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size(),
                                                 std::pmr::null_memory_resource()};

        // and allocate too much memory:
        std::pmr::unordered_map<long, std::pmr::string> coll {&pool};
        try {
            for (int i=0; i<buf.size(); ++i) {
                std::string s{"Customer" + std::to_string(i)};
                coll.emplace(i, s);
            }
        }
        catch (const std::bad_alloc& e) {
            //when memory requirement goes beyond what the buffer can serve a bad alloc exception is thrown
            std::cerr << "BAD ALLOC EXCEPTION: " << e.what() << '\n';
        }
        std::cout << "size: " << coll.size() << '\n';
    }

};

#endif //CPPLANGUAGEFEATURES_PMR_NULL_H
