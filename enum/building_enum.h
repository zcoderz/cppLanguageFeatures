  //
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_BUILDING_ENUM_H
#define CPPLANGUAGEFEATURES_BUILDING_ENUM_H

enum class building_enum {
    CONDO,HOUSE,APARTMENT
};

//we can define operators on enum
building_enum& operator++(building_enum & building) {
    switch (building) {
        case building_enum::CONDO : return building = building_enum::HOUSE;
        case building_enum::HOUSE : return building = building_enum::APARTMENT;
        case building_enum::APARTMENT : return building = building_enum::CONDO;
    }
}
#endif //CPPLANGUAGEFEATURES_BUILDING_ENUM_H
