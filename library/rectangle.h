//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_RECTANGLE_H
#define CPPLANGUAGEFEATURES_RECTANGLE_H

#include "coord.h"
#include <iostream>

class Rectangle {
private:
    coord from;
    coord to;
public:
    Rectangle (coord f, coord t)
            : from{f}, to{t} {
    }

    void move(const coord& c) {
        from += c;
        to += c;
    }

    void draw() const {
        std::cout << "rectangle from " << from
                  << " to " << to << '\n';
    }
};
#endif //CPPLANGUAGEFEATURES_RECTANGLE_H
