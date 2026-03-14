#include<iostream>
using namespace std;

int add(int x = 5,int y = 6) {
    return x + y;
}
//if no args, function will use default args set in the function

/* take note:
When you declare/define a function with an argument list, you must add defaults from right to left. 
That is, you cannot provide a default value for a particular argument unless you also provide defaults 
for all the arguments to its right

eg: 
int add(int x, int y = 5, int z = 6);       valid

int add(int x = 1, int y = 5, int z);       invalid

int add(int x = 1, int y, int z = 6);       invalid

actual arguements are assigned from left to right, you cannot skip over arguments


default args must be specified in fucntion declarations and avoid repeating default args in the function definition to prevent 
redefinition errors
*/

int main() {
    cout<< add(10,20)<<endl; //10+20, 30
    cout<<add(10) <<endl; //10+6, 16
    cout<<add() <<endl; //5+6, 11
    return 0;
}