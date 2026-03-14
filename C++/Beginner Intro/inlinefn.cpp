#include <iostream>
using namespace std;

// an inline function definition, use keyword "inline"
inline double square(double x) { return x * x; }

//used for simple tasks with short code, saves a large portion of time used by non inline call
//istead of fn calling, the compiler will literally replace the square() with the block defined in inline double during runtime
//but if the fn is too large, compiler will take it as a regular fn

int main() {
    double a, b;
    double c = 13.0;
    
    a = square(5.0);
    b = square(4.5 + 7.5);
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << endl;
    cout << "Now c = " << c << endl;
    
    return 0;
}