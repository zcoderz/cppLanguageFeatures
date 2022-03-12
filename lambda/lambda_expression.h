//
// Created by usman on 3/4/22.
//

#ifndef CPPLANGUAGEFEATURES_LAMBDA_EXPRESSION_H
#define CPPLANGUAGEFEATURES_LAMBDA_EXPRESSION_H

#include <vector>
#include <iostream>
#include <iterator>

class LambdaExpression {
public:
    template<typename C, typename Oper>
    static void for_all(C &c, Oper op) {
        for (auto  &v : c) {
            op(v);
        }
    }

    static void testLambdaExpression() {
        std::vector<int> vals = {1,2,3,4,5};
        for_all(vals, [&](int  & p){
            p = p*2;
        });
        std::copy(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, " "));
    }
    static void testLambda() {
        std::vector<int> vals = {1,2,3,4,5};
        std::for_each(vals.begin(), vals.end(), [&](int  & p){
            p = p*-1;
        });
        std::copy(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, " "));
    }
};

#endif //CPPLANGUAGEFEATURES_LAMBDA_EXPRESSION_H
