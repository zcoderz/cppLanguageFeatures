//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_CIRCLE_H
#define CPPLANGUAGEFEATURES_CIRCLE_H
#include "coord.h"
#include <iostream>

class circle {
private:
    coord center;
    int rad;
public:
    circle (coord c, int r)
            : center{c}, rad{r} {
    }

    void move(const coord& c) {
        center += c;
    }

    void draw() const {
        std::cout << "circle at " << center
                  << " with radius " << rad << '\n';
    }
};

#endif //CPPLANGUAGEFEATURES_CIRCLE_H
