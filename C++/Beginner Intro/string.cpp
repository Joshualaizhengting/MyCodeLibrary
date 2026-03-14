#include <iostream>
#include <string>       //if u want to use string need to declare this
using namespace std;

int main() {
    string s1("12345");
    string s2("abcde");

    // direct Concatenation
    string s3 = s1 + s2;
    cout<< "s3: "<<s3<<endl;
    
    // Printing each character of s1 using .at() and []
    for (int i = 0; i < s1.length(); i++)
        cout << s1.at(i);   //using cpp .at()
    cout << endl;
    
    for (int j = 0; j < s1.length(); j++)
        cout << s1[j];      //or just plain old string index
    cout << endl;

    
    // Insert a string s2 into s1 at position 4
    s1.insert(4, s2); // s1 becomes "1234abcde5"
    
    cout << "After insert: " << s1 << endl;
    
    
    // Remove 5 characters from s1 starting from position 4
    s1.erase(4, 5); // s1 becomes "12345"
    
    cout << "After erase: " << s1 << endl;
    
    
    // Replace 3 characters in s2 with s1 starting from position 1
    s2.replace(1, 3, s1); // s2 becomes "a12345e"
    
    cout << "After replace: " << s2 << endl;
    
    return 0;
}