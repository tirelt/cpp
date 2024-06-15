#include <iostream>

int main() 
{
    std::cout << "Be mindful of types !!" << std::endl;
    unsigned u = 10, v = 42, test = -1;
    long long number_bits = 0;
    std::cout << "u = " << u << ", v = " << v << std::endl;
    std::cout << "u - v = " << u - v << std::endl;
    number_bits = test + 1;
    std::cout << "Number of bits" << number_bits << std::endl;
    return 0;
}
