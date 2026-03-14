#include <iostream>
#include <limits>
using namespace std;
int main(){
    int age = 0;
    char name[20];
    cout <<"What is your name?"<<endl;
    cin >> name;
        //equiv to scanf in C
        //has the same issues of scanf as in C if there is whitespace, cannot continue to scan
        //cin will extract as much as it can to match the data types until it reaches whitespace or non digit chara
        //after it extracts, any remaining charas will stay in the stream => affects next input

    if (cin.fail()){
        cin.clear(); //clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard invlaid input
        cout << "Invalid Try again\n" <<endl;
    }
    
    cout<<"What is your age?" <<endl;
    cin>> age;
    cout<<"Your name is "<<name<<"< and you age is " << age <<endl;
    return 0;
}