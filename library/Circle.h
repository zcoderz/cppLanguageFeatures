//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_CIRCLE_H
#define CPPLANGUAGEFEATURES_CIRCLE_H
#include "Coord.h"
#include <iostream>

class Circle {
private:
    Coord center;
    int rad;
public:
    Circle (Coord c, int r)
            : center{c}, rad{r} {
    }

    void move(const Coord& c) {
        center += c;
    }

    void draw() const {
        std::cout << "circle at " << center
                  << " with radius " << rad << '\n';
    }
};

#endif //CPPLANGUAGEFEATURES_CIRCLE_H
