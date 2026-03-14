#include <iostream>
#include <iomanip>  //for setup precision and fixed
using namespace std;
int main(){
    int age = 25;
    cout <<"Age: "<< age<<endl;

    float pi = 3.1415;
    cout << "Pi: " << pi<<endl;

    double largenum = 12345677.89;
    cout << " LargeNum: "<<largenum<<endl;

    char grade = 'A';
    cout << "Grade: "<< grade<<endl;

    char name[] = "Alice";
    cout << "Hi"<<name<<endl;

    bool isstudent = true;
    cout << "Is " << name << " a student? " << boolalpha <<isstudent<<endl; //boolalpha converts 1 to True and 0 to false

    //multiple variables in one line
    int a = 10, b = 20;
    cout << "a: " << a << "b " << b << endl;

    //formatted floating-point output
    double num = 123.12313;
    cout << "Default: "<<num<<endl;
    cout << "Fixed: "<<fixed<<setprecision(2) <<num<<endl;
    //without fixed, setprecision sets it to 2 figures only, with fixed -> it sets it to exactly 2dp
    //only need to set once for remaining program; ie once set dont need to update
    return 0;
}