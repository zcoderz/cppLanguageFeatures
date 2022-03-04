//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_POLYVARIANT_H
#define CPPLANGUAGEFEATURES_POLYVARIANT_H

#include "../library/Line.h"
#include "../library/Circle.h"
#include "../library/Rectangle.h"
#include <variant>
#include <vector>
class PolyVariant {

    using GeoObj = std::variant<Line, Circle, Rectangle>;

// create and initialize a collection of geometric objects:
    std::vector<GeoObj> createFigure()
    {
        std::vector<GeoObj> f;
        f.push_back(Line{Coord{1,2},Coord{3,4}});
        f.push_back(Circle{Coord{5,5},2});
        f.push_back(Rectangle{Coord{3,3},Coord{6,4}});
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

#endif //CPPLANGUAGEFEATURES_POLYVARIANT_H
