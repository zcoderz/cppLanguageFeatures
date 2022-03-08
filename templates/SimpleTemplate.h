//
// Created by usman on 3/4/22.
//

#ifndef CPPLANGUAGEFEATURES_SIMPLETEMPLATE_H
#define CPPLANGUAGEFEATURES_SIMPLETEMPLATE_H


#include <stdexcept>

template<typename T>
class Vector {
private:
    T * elem;
    int sz;
public:
    explicit Vector(int sz) {
        if (sz <=0) throw std::out_of_range("out of range error ");
        elem = new T[sz];
    }

    const T & operator[](int i) const {
        if (sz <=i) throw std::out_of_range("out of range error ");
        return elem[i];
    }

    ~Vector() {
        delete elem;
    }
};

#endif //CPPLANGUAGEFEATURES_SIMPLETEMPLATE_H
