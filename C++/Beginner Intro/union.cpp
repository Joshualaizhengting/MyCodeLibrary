#include <iostream>
using namespace std;

union Data{
    short sValue;
    double dValue;
    
    void printShort(){ cout<<"sValue: " <<sValue<<endl;}
    void printDouble(){ cout<<"dValue: " <<dValue<<endl;}
};
/* A union is a data format that can hold different data types but only one type ata atime is used. All members share the same mem address
only uses the largest mem size

keyword union is not needed when declaring a union object
unions are often used to save memory space

*/

int main(){
    Data data;

    cout << "Size of Data: " << sizeof(Data) << " bytes."<<endl;
    
    cout << "Size of Short: " << sizeof(short) <<" bytes." <<endl;
    
    cout << "Size of Double: " << sizeof(double) << " bytes." <<endl<<endl;
    
    data.sValue = 42;
    cout << "Short: " << data.sValue << endl;
    data.printShort();
    
    data.dValue = 3.14; // Overwrites `sValue`
    cout << "Double: " << data.dValue << endl;
    data.printDouble();

    return 0;
}