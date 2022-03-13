//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_FIND_FIRST_OF_H
#define CPPLANGUAGEFEATURES_FIND_FIRST_OF_H

#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

namespace FindFirstOfExample {
    void main() {
        std::string str("Please, replace the vowels in this sentence by asterisks.");
        std::size_t found = str.find_first_of("aeiou");
        while (found != std::string::npos) {
            str[found] = '*';
            found = str.find_first_of("aeiou", found + 1);
        }

        std::cout << str << '\n';

    }
}
#endif //CPPLANGUAGEFEATURES_FIND_FIRST_OF_H
