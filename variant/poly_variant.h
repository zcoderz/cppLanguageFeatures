//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_POLY_VARIANT_H
#define CPPLANGUAGEFEATURES_POLY_VARIANT_H

#include "../library/line.h"
#include "../library/circle.h"
#include "../library/rectangle.h"
#include <variant>
#include <vector>
class PolyVariant {

    using GeoObj = std::variant<line, circle, Rectangle>;

// create and initialize a collection of geometric objects:
    std::vector<GeoObj> createFigure()
    {
        std::vector<GeoObj> f;
        f.push_back(line{coord{1, 2}, coord{3, 4}});
        f.push_back(circle{coord{5, 5}, 2});
        f.push_back(Rectangle{coord{3, 3}, coord{6, 4}});
        return f;
    }
public:
    void main()
    {
        std::vector<GeoObj> figure = createFigure();
        for (const GeoObj& geoobj : figure) {
            std::visit([] (const auto& obj) {
                           obj.draw();  // polymorphic call of draw()
                       },
                       geoobj);
        }
    }
};

#endif //CPPLANGUAGEFEATURES_POLY_VARIANT_H
