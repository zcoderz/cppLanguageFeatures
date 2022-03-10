//
// Created by usman on 3/10/22.
//

#ifndef CPPLANGUAGEFEATURES_COPY_EPSILON_MANDATORY_FOR_TEMPORARIES_H
#define CPPLANGUAGEFEATURES_COPY_EPSILON_MANDATORY_FOR_TEMPORARIES_H
#include <utility>
#include <memory>
#include <atomic>

class TestCopyEpsilon {
public:
    template <typename T, typename... Args>
    static T create(Args&&... args)
    {
        //the template type T is returned by value , but the compiler performs copy epsilon to
        //ensure that move and copy is not executed.
        return T{std::forward<Args>(args)...};
    }

    static void testCopyEpsilon() {
        std::unique_ptr<int> up = create<std::unique_ptr<int>>(new int{42});
        std::atomic<int> ai = create<std::atomic<int>>(42);
    }
};

#endif //CPPLANGUAGEFEATURES_COPY_EPSILON_MANDATORY_FOR_TEMPORARIES_H
