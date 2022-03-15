//
// Created by usman on 3/15/22.
//

#ifndef CPPLANGUAGEFEATURES_USING_EXAMPLE_TWO_H
#define CPPLANGUAGEFEATURES_USING_EXAMPLE_TWO_H

#include <list>
#include <memory>

//prefer using over typedef
namespace UsingExampleTwo {
    template<typename T>
    class MyAlloc : public std::allocator<T> {
    };

    template<typename T>
    using MyAllocList = std::list<T, MyAlloc<T>>;

    template<typename T>
    class Widget {
    private:
        MyAllocList<T> list;                         // no "typename",
        // ...                                       // no "::type"
    };
}
#endif //CPPLANGUAGEFEATURES_USING_EXAMPLE_TWO_H
