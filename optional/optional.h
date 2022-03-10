//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_OPTIONAL_H
#define CPPLANGUAGEFEATURES_OPTIONAL_H
#include <optional>
#include <string>
#include <iostream>


class Optional {
    static std::optional<int> asInt(const std::string& s)
    {
        try {
            return std::stoi(s);
        }
        catch (...) {
            return std::nullopt;
        }
    }

public:

    static void testMe()
    {
        for (auto s : {"42", "  077", "hello", "0x33"} ) {
            // try to convert s to int and print the result if possible:
            std::optional<int> oi = asInt(s);
            if (oi) {
                std::cout << "convert '" << s << "' to int: " << *oi << "\n";
            }
            else {
                std::cout << "can't convert '" << s << "' to int\n";
            }
        }
    }

};
#endif //CPPLANGUAGEFEATURES_OPTIONAL_H
