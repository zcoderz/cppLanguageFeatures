//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_COORD_H
#define CPPLANGUAGEFEATURES_COORD_H

#include <ostream>

class coord {
private:
    int x;     // x coordinate
    int y;     // y coordinate
public:
    // default constructor:
    coord() : x{0}, y{0} {
    }
    // other constructor:
    coord(int newx, int newy) : x{newx}, y{newy} {
    }

    friend coord operator+ (coord c1, coord c2) {  // plus
        return coord{c1.x + c2.x, c1.y + c2.y};
    }
    friend coord operator- (coord c1, coord c2) {  // diff
        return coord{c1.x - c2.x, c1.y - c2.y};
    }
    coord operator- () const {                     // negate
        return coord{-x, -y};
    }
    void operator+= (coord c) {                    // +=
        *this = *this + c;  // or: x+=c.x, y+=c.y
    }
    void operator-= (coord c) {                    // +=
        operator+=(-c);     // or as above
    }

    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    friend std::ostream& operator<< (std::ostream& strm, coord c) {
        return strm << '(' << c.x << ',' << c.y << ')';
    }
};
#endif //CPPLANGUAGEFEATURES_COORD_H
