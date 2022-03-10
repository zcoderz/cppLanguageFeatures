//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_EXCEPTION_CPP
#define CPPLANGUAGEFEATURES_EXCEPTION_CPP

#include <exception>
#include "exception.h"
#include <iostream>


class TestThrow : public std::exception {
public:
    const char *what() const throw() {
        return "some exception";
    }
};

void Exception::testExceptions() {
    try {
        throw TestThrow();
    } catch (TestThrow &ex) {
        std::cout << "T1: " << ex.what() << std::endl;
    } catch (std::exception & exception) {
        std::cout << exception.what() << std::endl;
    } catch (...) {
        std::cout << "zzz" << std::endl;
    }
}

#endif //CPPLANGUAGEFEATURES_EXCEPTION_CPP
