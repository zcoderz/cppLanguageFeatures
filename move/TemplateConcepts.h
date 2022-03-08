//
// Created by usman on 3/7/22.
//

#ifndef CPPLANGUAGEFEATURES_TEMPLATECONCEPTS_H
#define CPPLANGUAGEFEATURES_TEMPLATECONCEPTS_H

#include <string>
#include <string_view>

// require a universal reference of a specific type:
// - no implicit type conversions supported
template<typename T>
requires std::is_same_v<std::remove_cvref_t<T>, std::string>
void requireSame(T&&) {
    //...
}

// require a universal reference of a specific type:
// - implicit but no explicit type conversions supported
template<typename T>
requires std::is_convertible_v<T, std::string>
void requireConvertible(T&&) {
    //...
}

// require a universal reference of a specific type:
// - even explicit type conversions supported
// note: the order of arguments differs
template<typename T>
requires std::is_constructible_v<std::string, T>
void requireConstructible(T&&) {
    //...
}


void testTemplateConcepts()
{
    std::string s = "hi";
    std::string_view sv = "hi";

    requireSame(s);              // OK
    //requireSame(sv);           // ERROR: no std::string
    //requireSame("hi");         // ERROR: no std::string

    requireConvertible(s);       // OK
    //requireConvertible(sv);    // ERROR: not implicit conversion to std::string
    requireConvertible("hi");    // OK

    requireConstructible(s);     // OK
    requireConstructible(sv);    // OK (explicit conversion used)
    requireConstructible("hi");  // OK
}
#endif //CPPLANGUAGEFEATURES_TEMPLATECONCEPTS_H