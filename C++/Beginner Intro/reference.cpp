#include <iostream>

int main(){
    using namespace std;
    int rats = 101;
    int & rodents = rats;// rodents is a reference
    
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    //mem address of rats and rodents are the same
    
    int bunnies = 50;
    
    rodents = bunnies; // can we change the reference? no 
    //value is changed but the memory address does not
    //assign the value of bunnies to the memory location of rodents, original address of rodents is unchanged
    
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;
    
    return 0;
}