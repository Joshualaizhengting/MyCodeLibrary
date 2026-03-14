#include <iostream>
/*designed namespaces to help avoid possible naming conflicts: 
eg 2 libraries may define list, tree and node differently but with the same name
*/

//if we do not use using namespace std, need to use std:: prefix
//std namespace defined in the iostream file contains the def for cin and cout

int main(){
    //explictedly specify the appropriate length space
    //program knows im using cout defined in the std lengthspace
    std::cout << "Hello World" << std::endl;
    std::cout << "Hi\n";
    return 0;
}