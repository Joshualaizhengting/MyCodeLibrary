#include <iostream>
int main() {
    int value1 = 10;
    int value2 = 20;
    
    //constant pointer
    int* const ptr1 = &value1; 
    *ptr1 = 15; // Allowed
    //ptr1 = &value2; // Not allowed because you cannot change a constant pointer
    
    
    //pointer pointing to a constant entity
    const int* ptr2 = &value1; 
    //ptr2 = 15; // Not allowed, because an integer value cannot be assigned to a pointer, not legal anyways
    //*ptr2 = 15; // Not allowed 
    ptr2 = &value2; 


    //const pointer pointing to a constant entity
    const int* const ptr3 = &value1;
    //*ptr3 = 15; // Not allowed
    //ptr3 = &value2; // Not allowed
    
    
    return 0;
}
//uncomment to see that cpp does not allow and will throw back an error
