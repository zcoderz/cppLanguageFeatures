//
// Created by usman on 3/15/22.
//

#ifndef CPPLANGUAGEFEATURES_OVERRIDE_EXAMPLE_H
#define CPPLANGUAGEFEATURES_OVERRIDE_EXAMPLE_H
#include <iostream>

namespace OverrideExample {

    struct A
    {
        virtual void foo();
        void bar();
        virtual ~A();
    };

// member functions definitions of struct A:
    void A::foo() { std::cout << "A::foo();\n"; }
    A::~A() { std::cout << "A::~A();\n"; }

    struct B : A
    {
//  void foo() const override; // Error: B::foo does not override A::foo
        // (signature mismatch)
        void foo() override; // OK: B::foo overrides A::foo
        //  void bar() override; // Error: A::bar is not virtual
        ~B() override; // OK: `override` can also be applied to virtual special member functions, e.g. destructors
        void override(); // OK, member function name, not a reserved keyword
    };

// member functions definitions of struct B:
    void B::foo() { std::cout << "B::foo();\n"; }
    B::~B() { std::cout << "B::~B();\n"; }
    void B::override() { std::cout << "B::override();\n"; }

    void main() {
        B b;
        b.foo();
        b.override(); // OK, invokes the member function `override()`
        int override{42}; // OK, defines an integer variable
        std::cout << "override: " << override << '\n';
    }

}
#endif //CPPLANGUAGEFEATURES_OVERRIDE_EXAMPLE_H
