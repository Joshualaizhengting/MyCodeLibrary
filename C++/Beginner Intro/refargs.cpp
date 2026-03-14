#include <iostream>
// passing by reference
//use const ref to avoid unexpected var changes
double calVolume(const double& a) {
    double vol = a * a * a;
    return vol;
}
    int main() {
    double x = 3.0;
    double volume = calVolume(x);
    std::cout << "Original side length: " << x << std::endl; // Outputs: 3
    std::cout << "Volume of the cube: " << volume << std::endl; // Outputs: 27
    return 0;
}