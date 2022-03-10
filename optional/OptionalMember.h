//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_OPTIONALMEMBER_H
#define CPPLANGUAGEFEATURES_OPTIONALMEMBER_H

#include <string>
#include <optional>
#include <iostream>

class OptionalMember {
    class Name
    {
    private:
        std::string first;
        std::optional<std::string> middle;
        std::string last;
    public:
        Name (std::string f,
              std::optional<std::string> m,
              std::string l)
                : first{std::move(f)}, middle{std::move(m)}, last{std::move(l)} {
        }
        friend std::ostream& operator << (std::ostream& strm, const Name& n) {
            strm << n.first << ' ';
            if (n.middle) {
                strm << *n.middle << ' ';
            }
            return strm << n.last;
        }
    };

public:
    static void testMe()
    {
        Name n{"Jim", std::nullopt, "Knopf"};
        std::cout << n << '\n';

        Name m{"Donald", "Ervin", "Knuth"};
        std::cout << m << '\n';
    }

};

#endif //CPPLANGUAGEFEATURES_OPTIONALMEMBER_H
