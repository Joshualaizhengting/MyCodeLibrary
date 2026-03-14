#include <iostream>
void swapr(int &a, int &b);     //a, b are aliases for ints
void swapp(int * p, int * q);   //p, q are addresses of ints
void swapv(int a, int b);       // a, b are new vars

int main(){
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout <<"Wallet1 = $" <<wallet1;
    cout <<" allet2 = $" <<wallet2 <<endl<<endl;

    cout <<"using ref to swap: \n";
    swapr(wallet1, wallet2);    //passing variables
    cout <<"Wallet1 = $" <<wallet1;
    cout <<" Wallet2 = $" <<wallet2 <<endl<<endl;

    cout <<"using pointers to swap: \n";
    swapp(&wallet1, &wallet2);
    cout <<"Wallet1 = $" <<wallet1;
    cout <<" Wallet2 = $" <<wallet2 <<endl<<endl;

    cout<< "Trying to use pass by values: \n";
    swapv(wallet1, wallet2);
    cout <<"Wallet1 = $" <<wallet1;
    cout <<" Wallet2 = $" <<wallet2 <<endl<<endl;
    return 0;
}

void swapr(int &a, int &b){
    int temp;

    temp = a;
    a = b;      //use a, b for values of variable
    b = temp;   //successful swap
}

void swapp(int * p, int * q){
    int temp;

    temp = *p;
    *p = *q;      //use *p, *q for values of variable
    *q = temp;    //successful swap 
}

void swapv(int a, int b){
    int temp;
                //a and b are local vars which will not be reflected in the main function => no return value
    temp = a;
    a = b;      //use a, b for values of variable
    b = temp;   //failed swap

}