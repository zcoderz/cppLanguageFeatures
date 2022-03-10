//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_LINE_H
#define CPPLANGUAGEFEATURES_LINE_H

#include "coord.h"
#include <iostream>

class line {
private:
    coord from;
    coord to;
public:
    line (coord f, coord t)
            : from{f}, to{t} {
    }

    void move(const coord& c) {
        from += c;
        to += c;
    }

    void draw() const {
        std::cout << "line from " << from
                  << " to " << to << '\n';
    }
};
#endif //CPPLANGUAGEFEATURES_LINE_H
