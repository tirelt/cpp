#include <iostream>

struct Myclass {
    Myclass() = default;
    int a;
};

int main() {
    std::cout << "Hello" << std::endl;
    if (1) {
        int a = 1;
    }
    return 0;
}