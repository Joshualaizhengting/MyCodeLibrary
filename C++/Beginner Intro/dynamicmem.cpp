#include <iostream>
using namespace std;
int main() {
    //use "new" for allocating dynamic mem

    int* pt = new int; // Allocate memory for an integer
    *pt = 42;

    cout << "Value: " << *pt << ", memory address: "<< pt << endl;

    delete pt; 
    //need to Free memory, use delete, if u dont it will cause mem leakage in the program like in java need to close the scan obj
    
    cout << "Value: " << *pt << ", memory address: "<< pt << endl;
    
    //pt may still point to the prev mem access
    pt = nullptr; // prevents dangling pointer, nullptr: null pointer
    
    cout<< "memory address: " << pt <<endl; //pt now is a random var
    
    return 0;
}