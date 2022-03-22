//
// Created by usman on 3/21/22.
//

#ifndef CPPLANGUAGEFEATURES_VIEWS_PIPE_H
#define CPPLANGUAGEFEATURES_VIEWS_PIPE_H

#include <iostream>
#include <vector>
#include <map>
#include <ranges>

namespace ViewsPipe {
    void main() {
        namespace vws = std::views;

        std::vector<int> vals{0, 1, 2, 3, 4};

        // map of composers names and their years of birth:
        std::map<std::string, int> composers{
                {"Bach",        1685},
                {"Mozart",      1756},
                {"Beethoven",   1770},
                {"Tchaikovsky", 1840},
                {"Chopin",      1810},
                {"Vivaldi ",    1678},
        };

        // iterate over the names of the first 3 composers born since 1700:
        for (const auto &elem: composers
                               | vws::filter([](const auto &y) {   // since 1700
            return y.second >= 1700;
        })
                               | vws::take(3)                      // first 3
                               | vws::keys                         // keys/names only
                ) {
            std::cout << "- " << elem << '\n';
        }

    }
}
#endif //CPPLANGUAGEFEATURES_VIEWS_PIPE_H
