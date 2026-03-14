#include <iostream>
#include "greet.h"
using namespace English;

int main(){
    //calls the function from the English namespace
    greet();

    //redefine Japanese namespace
    //explictely spaceify the namespace
    Japanese::greet();

    return 0;
}