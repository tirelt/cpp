#include <iostream>

int main()
{
    int val = 10;
    while (val >=0) { 
        std::cout << "Count down at " << val << std::endl;
        --val;
    }
	return 0;
}
