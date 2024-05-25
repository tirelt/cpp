#include <iostream> 

int main() 
{
	int sum = 0, value = 0, max_numer = 5, ite = 0;
	// read until end-of-file, calculating a running total of all values read
	while (std::cin >> value) {
		sum += value; // equivalent to sum = sum + value
		std::cout << "Current sum is: " << sum << std::endl;
		++ite;
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}