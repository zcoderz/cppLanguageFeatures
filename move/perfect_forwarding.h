//
// Created by usman on 3/7/22.
//

#ifndef CPPLANGUAGEFEATURES_PERFECT_FORWARDING_H
#define CPPLANGUAGEFEATURES_PERFECT_FORWARDING_H

#include <utility>  // for forward<>()
#include <string>
#include <iostream>

template <typename Func, typename... Args>
decltype(auto) call (Func f, Args&&... args)
{
    //forward the arguments
    return f(std::forward<Args>(args)...);
}

class TestForwarding {
    public:
    static std::string nextString()
    {
        return "Let's dance";
    }

    static std::ostream& print(std::ostream& strm, const std::string& val)
    {
        return strm << "value: " << val;
    }

    static std::string&& returnArg(std::string&& arg)
    {
        return std::move(arg);
    }

    static void testMain()
    {
        auto s = call(nextString);                   // call() returns temporary object

        auto&& ref = call(returnArg, std::move(s));  // call() returns rvalue reference to s
        std::cout << "s:   " << s << '\n';
        std::cout << "ref: " << ref << '\n';

        auto str = std::move(ref);                   // move value from s and ref to str
        std::cout << "s: "   << s << '\n';
        std::cout << "ref: " << ref << '\n';
        std::cout << "str: " << str << '\n';

        call(print, std::cout, str) << '\n';         // call() returns reference to std::cout
    }

};
#endif //CPPLANGUAGEFEATURES_PERFECT_FORWARDING_H
