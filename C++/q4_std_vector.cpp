#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <numeric>   // for std::accumulate

int main() {
    // Declare a vector to store daily sales.
    std::vector<int> dailySales;
    
    // TO-DO: Add seven daily sales values to the vector: 
    //         120, 200, 150, 80, 90, 220, 100
    //
    //
    dailySales.push_back(120);
    dailySales.push_back(200);
    dailySales.push_back(150);
    dailySales.push_back(80);
    dailySales.push_back(90);
    dailySales.push_back(220);
    dailySales.push_back(100);

    // TO-DO: Print all sales values by using an iterator
    //
    //
    std::vector<int>::iterator it;
    std::cout << "Daily Sales: ";
    for (it = dailySales.begin(); it != dailySales.end(); it++){
        std::cout << *it <<" ";
    }
    std::cout << std::endl;

    
    // TO-DO: Calculate the average of the sales values and print it
    //
    //
    double sum = 0.0;
    double average = 0.0;

    for (it = dailySales.begin(); it != dailySales.end(); it++){
        sum += double(*it);
    }
    average = sum/7;
    std::cout << "Average Sales: " <<average << "\n";


    

    // TO-DO: Sort the vector in ascending order using std::sort.
    //
    sort(dailySales.begin(), dailySales.end());
    
    
    // TO-DO: Print all the sorted sales values by using an iterator
    //
    //
    std::cout << "Sorted Sales: ";
    for (it = dailySales.begin(); it != dailySales.end(); it++){
        std::cout << *it <<" ";
    }
    std::cout << std::endl;
    
    
    return 0;
}
