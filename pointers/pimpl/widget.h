//
// Created by usman on 3/15/22.
//

#ifndef CPPLANGUAGEFEATURES_WIDGET_H
#define CPPLANGUAGEFEATURES_WIDGET_H
#include <memory>

class Widget {                  // in "widget.h"
public:
    Widget();
    ~Widget();                    // declaration only

    //Widget(Widget&& rhs) = default;             // right idea
    //Widget& operator=(Widget&& rhs) = default;  // wrong code!

    Widget(Widget&& rhs);                         // declarations
    Widget& operator=(Widget&& rhs);              // only

    Widget(const Widget& rhs);                    // declarations
    Widget& operator=(const Widget& rhs);         // only

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;  // use smart pointer
};
#endif //CPPLANGUAGEFEATURES_WIDGET_H
