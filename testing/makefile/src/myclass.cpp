#include "myclass.h"
#include "lib1.h"

void Myclass::set_value(int v){
    int a = dummy1();
    value = a * v;
}
