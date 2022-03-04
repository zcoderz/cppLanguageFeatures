//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_LINE_H
#define CPPLANGUAGEFEATURES_LINE_H

#include "Coord.h"
#include <iostream>

class Line {
private:
    Coord from;
    Coord to;
public:
    Line (Coord f, Coord t)
            : from{f}, to{t} {
    }

    void move(const Coord& c) {
        from += c;
        to += c;
    }

    void draw() const {
        std::cout << "line from " << from
                  << " to " << to << '\n';
    }
};
#endif //CPPLANGUAGEFEATURES_LINE_H
