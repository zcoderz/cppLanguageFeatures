//
// Created by usman on 3/14/22.
//

#ifndef CPPLANGUAGEFEATURES_USING_EXAMPLE_H
#define CPPLANGUAGEFEATURES_USING_EXAMPLE_H

#include <memory>
#include <iostream>

namespace UsingExample {
    using std::shared_ptr;
    struct Item {
        int val;
    };
    using ItemPtr = shared_ptr<Item>;
    enum class fruit  { orange, apple };
    void testMe() {
        ItemPtr itemPtr = ItemPtr (new Item);
        itemPtr->val = 200;
        using enum fruit;
        using std::cout;
        cout << "orange = " << static_cast<int>(orange) << ", apple : " << static_cast<int>(apple) << ", item val = " << itemPtr->val << std::endl;
    }
}

#endif //CPPLANGUAGEFEATURES_USING_EXAMPLE_H
