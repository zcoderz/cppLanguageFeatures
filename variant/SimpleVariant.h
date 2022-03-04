//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_SIMPLEVARIANT_H
#define CPPLANGUAGEFEATURES_SIMPLEVARIANT_H
#include <variant>
#include <iostream>

class SimpleVariant {
public:
    void test() {
        std::variant<int, std::string> var{"hi"};  // initialized with string alternative
        if (auto val = std::get_if<0>(&var); val != nullptr) {
            std::cout << " Variant value is an integer : " << val << std::endl;
        }
        std::cout << var.index() << '\n';          // prints 1
        var = 42;                                  // now holds int alternative
        std::cout << var.index() << '\n';          // prints 0
        //...
        try {
            int i = std::get<0>(var);                    // access by index
            std::string s = std::get<std::string>(var);  // access by type (throws exception here)
            //...
        }
        catch (const std::bad_variant_access& e) {     // in case a wrong type/index is used
            std::cerr << "EXCEPTION: " << e.what() << '\n';
            //...
        }
    }
};

#endif //CPPLANGUAGEFEATURES_SIMPLEVARIANT_H
