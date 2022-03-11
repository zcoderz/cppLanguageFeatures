//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_PMR_CUSTOMER_H
#define CPPLANGUAGEFEATURES_PMR_CUSTOMER_H
#include <string>
#include <memory_resource>
#include "tracker.h"
#include <iostream>
#include <vector>

// Customer as polymorphic-allocator-aware type
// - the allocator is stored in the string member
class PmrCustomer
{
private:
    std::pmr::string name;  // also used to store the allocator

    using allocator_type = std::pmr::polymorphic_allocator<char>;

    // initializing constructor(s):
    PmrCustomer(std::pmr::string n, allocator_type alloc = {})
            : name{std::move(n), alloc} {
    }

    // copy/move with allocators:
    PmrCustomer(const PmrCustomer& c, allocator_type alloc)
            : name{c.name, alloc} {
    }
    PmrCustomer(PmrCustomer&& c, allocator_type alloc)
            : name{std::move(c.name), alloc} {
    }

    // setters/getters:
    void setName(std::pmr::string s) {
        name = std::move(s);
    }
    std::pmr::string getName() const {
        return name;
    }
    std::string getNameAsString() const {
        return std::string{name};
    }

public:
    static void testMe()
    {
        Tracker tracker;
        std::pmr::vector<PmrCustomer> coll(&tracker);
        coll.reserve(100);                     // allocates with tracker

        // allocates with get_default_resource() ,
        // can allocate with tracker and then will be able to utilize move correctly
        PmrCustomer c1{"Peter, Paul & Mary"};
        coll.push_back(c1);                    // allocates with vector allocator (tracker)
        coll.push_back(std::move(c1));         // copies (allocators not interchangeable)

        for (const auto& cust : coll) {
            std::cout << cust.getName() << '\n';
        }
    }
};

#endif //CPPLANGUAGEFEATURES_PMR_CUSTOMER_H
