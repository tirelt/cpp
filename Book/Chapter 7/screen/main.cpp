#include <string>
#include <iostream>
#include <vector>
#include "screen.h"
#include "window_mgr.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main(){
    Screen default_screen(cin);
    default_screen.print(cout)<< endl;
    Window_mgr mywindomgr(3,default_screen);
    
    mywindomgr.get_screen(0).set(1, 1, 'T');
    mywindomgr.get_screen(1).set(3, 2, 'O');

    mywindomgr.print(cout);

    return 0;
};
