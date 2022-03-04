//
// Created by usman on 3/3/22.
//

#include "SampleNameSpace.h"

#include <iostream>


namespace  {
    //variables in unnamed namespace have visibility local to the file where they are declared
    int j;
    int k;
}

//only one instance of the variable blah exists for the life of the program
//this variable is initialized at compile time and before the program starts
static int blah = 10;

namespace SampleNamespace {
    void Greeting::hello() {
        std::cout << "Hello world!" << std::endl;
    }
}