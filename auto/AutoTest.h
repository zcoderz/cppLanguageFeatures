//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_AUTOTEST_H
#define CPPLANGUAGEFEATURES_AUTOTEST_H


#include <iostream>

class AutoTest {
private:
    struct TempObj {
        int i;
        double j;
    };

    TempObj returnSomething() {
        int i =1;
        double j = 2;
        return {i,j};
    }

public:

    void testAuto() {
        auto [m,n] = returnSomething();
        std::cout << " m = " << m << " n =" << n << std::endl;
    }


};

#endif //CPPLANGUAGEFEATURES_AUTOTEST_H
