//
// Created by usman on 3/7/22.
//

#ifndef CPPLANGUAGEFEATURES_RETURNVALUE_H
#define CPPLANGUAGEFEATURES_RETURNVALUE_H

#include <string>
#include <iostream>

class ReturnValueTest {
public:

    std::string testStr = "abcd";

    std::string testReturnValueOpt() {
        return "return-value-opt";
    }

    std::string testNamedReturnValueOpt() {
        std::string str = "blah";
        return str;
    }

    std::string && returnRValue () {
        //std::string tmp = "uq";
        return std::move(testStr);
    }

    const std::string & returnConstRef ()  {
        return testStr;
    }

    static void testRetVal() {
        ReturnValueTest returnValueTest;
        const std::string & str = returnValueTest.returnConstRef();
        std::cout << "Returned by const ref " << str << std::endl;

        std::string && rValue = returnValueTest.returnRValue();
        std::cout << "Returned by r value " << rValue << std::endl;

        std::cout << "RVO: "<< returnValueTest.testReturnValueOpt() << std::endl;
        std::cout << "Named RVO: " << returnValueTest.testNamedReturnValueOpt() << std::endl;
    }

};

#endif //CPPLANGUAGEFEATURES_RETURNVALUE_H
