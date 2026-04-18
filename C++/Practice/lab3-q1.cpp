///////// Student Info/////////
//
//           Your Name:__________
//      Your NTU Email:__________
//
//
//

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    // Constructor
    Product(string productName, double productPrice) {
        //TO-DO: Write Your Code Here
        //
        //
        this->name = productName;
        this->price = productPrice;

    }

    // Destructor
    //TO-DO: Write Your Code Here
    //
    //
    ~Product(){}

    // Getters
    //TO-DO: Write Your Code Here
    //
    //
    string getName(){
        return this->name;
    }
    double getPrice(){
        return this->price;
    }

    // Setter for price (ensures non-negative value)
    void setPrice(double newPrice) {
        //TO-DO: Write Your Code Here
        //
        //
        if (newPrice>0){
            this->price = newPrice;
        }else{
            cout << "Negative Price";
        }

    }
};


int main() {
    // Creating Product objects
    Product product1("Laptop", 999.99);
    Product product2("Phone", 499.50);

    // Displaying product details
    cout<<endl;
    cout << "The name of Product 1: " << product1.getName() << endl;
    cout<< "The price of Product 1: $" << product1.getPrice() << endl;
    cout<<endl;

    // Modifying product price with setter
    product2.setPrice(550.00);
    cout << "Updated Price of Product 2: $" << product2.getPrice() << endl;

    return 0;
}
