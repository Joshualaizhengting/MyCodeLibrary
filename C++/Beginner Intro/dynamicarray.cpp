#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    // Allocate memory for an array dynamically
    int* arr = new int[size];

    // Input values
    cout << "Enter " << size << " elements: ";

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display values
    cout << "You entered: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Deallocate memory
    delete[] arr;

    arr = nullptr; // Prevent dangling pointer

    return 0;
    //new and delete should be in pairs 1 new -> 1 delete, new array[] -> delete[] and new pointer -> delete pointer. 
}