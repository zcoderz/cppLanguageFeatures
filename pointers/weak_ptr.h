//
// Created by usman on 3/12/22.
//

#ifndef CPPLANGUAGEFEATURES_WEAK_PTR_H
#define CPPLANGUAGEFEATURES_WEAK_PTR_H
#include <iostream>
#include <memory>
namespace WeakPtr {
    std::weak_ptr<int> gw;

    void observe()
    {
        std::cout << "gw.use_count() == " << gw.use_count() << "; ";
        // we have to make a copy of shared pointer before usage:
        if (std::shared_ptr<int> spt = gw.lock()) {
            std::cout << "*spt == " << *spt << '\n';
        }
        else {
            std::cout << "gw is expired\n";
        }
    }
    class WeakPtr {
    public:
        static void testMe()
        {
            {
                auto sp = std::make_shared<int>(42);
                gw = sp;

                observe();
            }

            observe();
        }
    };
}
#endif //CPPLANGUAGEFEATURES_WEAK_PTR_H
