//
// Created by usman on 3/3/22.
//

#ifndef CPPLANGUAGEFEATURES_BUILDINGENUM_H
#define CPPLANGUAGEFEATURES_BUILDINGENUM_H

enum class BuildingEnum {
    CONDO,HOUSE,APARTMENT
};

//we can define operators on enum
BuildingEnum& operator++(BuildingEnum & building) {
    switch (building) {
        case BuildingEnum::CONDO : return building = BuildingEnum::HOUSE;
        case BuildingEnum::HOUSE : return building = BuildingEnum::APARTMENT;
        case BuildingEnum::APARTMENT : return building = BuildingEnum::CONDO;
    }
}
#endif //CPPLANGUAGEFEATURES_BUILDINGENUM_H
