#include <iostream>
int main(){
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout <<"Enter your name: \n";
    cin.get(name, ArSize);  //read the whole string
    cin.get();              // read the newline char at the end

    cout << "Enter dessert: \n";
    cin.get(dessert, ArSize).get();     
    
    //function concatenate, as cin.get(dessert) will return the object cin
    //extra.get() at the back helps do the above cin.get without having to explictely write cin.get again

    cout << "I have some delicious " <<dessert;
    cout <<" for you "<<name;
    return 0;
}