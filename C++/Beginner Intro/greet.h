//ln greet.h
#pragma once
#include <iostream>

//demonstrating lengthspaces, we can also define our own length space
namespace English{
    void greet(){
        std::cout<<"Hello"<<std::endl;
    }
}

namespace Japanese{
    void greet(){
        std::cout<<"Konnichiwa"<<std::endl;
    }
}

