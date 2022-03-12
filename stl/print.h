//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_PRINT_H
#define CPPLANGUAGEFEATURES_PRINT_H
#include <iostream>
#include <string>

// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
template <typename T>
inline void PRINT_ELEMENTS (const T& coll,
                            const std::string& optstr="")
{
    std::cout << optstr;
    for (const auto&  elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}
#endif //CPPLANGUAGEFEATURES_PRINT_H
