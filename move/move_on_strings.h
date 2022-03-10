//
// Created by usman on 3/7/22.
//

#ifndef CPPLANGUAGEFEATURES_MOVE_ON_STRINGS_H
#define CPPLANGUAGEFEATURES_MOVE_ON_STRINGS_H
#include <iostream>
class MoveOnStrings {
public :

    //Shows that the moved from objects are still valid after move.
    //But their data is invalid. For example, the capacity shows prior value but string is obviously empty, size is correctly updated

    static void testMe() {
        std::string s0;
        std::string s1{"short"};
        std::string s2{"a string with an extraordinarily long value"};
        std::cout << "- s0 capa: " << s0.capacity() << " ('" << s0 << "')\n";
        std::cout << "  s1 capa: " << s1.capacity() << " ('" << s1 << "')\n";
        std::cout << "  s2 capa: " << s2.capacity() << " ('" << s2 << "')\n";

        std::string s3{std::move(s1)};
        std::string s4{std::move(s2)};

        std::cout << "- s1 capa: " << s1.capacity() << " ('" << s1 << "') "<< " sz " << s1.size() << "\n";
        std::cout << "  s2 capa: " << s2.capacity() << " ('" << s2 << "')\n";
        std::cout << "  s3 capa: " << s3.capacity() << " ('" << s3 << "')\n";
        std::cout << "  s4 capa: " << s4.capacity() << " ('" << s4 << "')\n";

        std::string s5{"quite a reasonable value"};
        std::cout << "- s4 capa: " << s4.capacity() << " ('" << s4 << "')\n";
        std::cout << "  s5 capa: " << s5.capacity() << " ('" << s5 << "')\n";

        s4 = std::move(s5);
        std::cout << "- s4 capa: " << s4.capacity() << " ('" << s4 << "')\n";
        std::cout << "  s5 capa: " << s5.capacity() << " ('" << s5 << "')\n";
    }
};
#endif //CPPLANGUAGEFEATURES_MOVE_ON_STRINGS_H
