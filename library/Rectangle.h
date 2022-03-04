//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_RECTANGLE_H
#define CPPLANGUAGEFEATURES_RECTANGLE_H

#include "Coord.h"
#include <iostream>

class Rectangle {
private:
    Coord from;
    Coord to;
public:
    Rectangle (Coord f, Coord t)
            : from{f}, to{t} {
    }

    void move(const Coord& c) {
        from += c;
        to += c;
    }

    void draw() const {
        std::cout << "rectangle from " << from
                  << " to " << to << '\n';
    }
};
#endif //CPPLANGUAGEFEATURES_RECTANGLE_H
