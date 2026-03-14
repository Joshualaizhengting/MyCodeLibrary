#include <iostream>
using namespace std;
struct Person {
    char name[50];
    int age;
    float height;

    //Difference 1: A structure in C++ can have member functions --- OOP concepts
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", Height: " << height <<endl;
    }
};

int main() {

    Person p1 = {"Alice", 25, 175};    //Difference 2: No need to use `struct` keyword here in C++
    p1.display();
    return 0;
}