#include <iostream>
using namespace std;
class A{
public:
    A(){
        cout << "00";
    }
    A(int x){
        cout <<x;
    };
};

class B{
public:
    A obj1, obj2;
    B(int i);
};

B::B(int i):obj1(A(i)){
    obj2 = A(i+5);
    cout << "B";
}

int main(){
    B obj(3);
}