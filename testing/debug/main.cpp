#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Myclass {
    Myclass() = default;
    int a;
    int b = 0;
};

int main() {
    Myclass obj;
    return 0;
}