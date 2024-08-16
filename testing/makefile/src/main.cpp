#include "myclass.h"
#include "lib2.h"
#include "iostream"

int main(){
    Myclass o;
    o.set_value(dummy2());
    std::cout << "test 2" << std::endl; 
    return 0;
}