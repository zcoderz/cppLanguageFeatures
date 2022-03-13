//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_CONTAINER_SPLICE_AND_MERGE_H
#define CPPLANGUAGEFEATURES_CONTAINER_SPLICE_AND_MERGE_H
#include <iostream>
#include <string>
#include <map>


class ContainerSpliceAndMerge {
    template<typename T1, typename T2>
    static void print(const T1& coll1, const T2& coll2)
    {
        std::cout << "values:\n";
        for (const auto& [key, value] : coll1) {
            std::cout << "  [" << key << ":" << value << "]";
        }
        std::cout << '\n';
        for (const auto& [key, value] : coll2) {
            std::cout << "  [" << key << ":" << value << "]";
        }
        std::cout << '\n';
    }

public:
    static void testMerge() {
        std::multimap<double, std::string> src {{1.1, "one"},
                                                {2.2, "two"},
                                                {3.3, "three"}};
        std::map<double, std::string> dst {{3.3, "old data"}};

        print(src, dst);

        // merge all elements from src into dst:
        dst.merge(src);
        print(src, dst);
    }

    static void testSplice() {
        std::multimap<double, std::string> src {{1.1, "one"},
                                                {2.2, "two"},
                                                {3.3, "three"}};
        std::map<double, std::string> dst {{3.3, "old data"}};

        print(src, dst);

        // move some elements from multimap src to map dst:
        dst.insert(src.extract(src.find(1.1)));  // splice using an iterator
        dst.insert(src.extract(2.2));            // splice using the key

        print(src, dst);
    }
};

#endif //CPPLANGUAGEFEATURES_CONTAINER_SPLICE_AND_MERGE_H
