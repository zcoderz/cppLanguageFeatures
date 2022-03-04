cmake_minimum_required(VERSION 3.21)
project(cppLanguageFeatures)

set(CMAKE_CXX_STANDARD 23)



add_executable(cppLanguageFeatures main.cpp library/Line.h library/Coord.h library/Circle.h library/Rectangle.h variant/SimpleVariant.h variant/PolyVariant.h enum/BuildingEnum.h namespace/SampleNameSpace.h namespace/SampleNamespace.cpp exceptions/Exception.cpp exceptions/Exception.h)


