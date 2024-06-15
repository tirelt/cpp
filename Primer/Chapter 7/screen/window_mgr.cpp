#include <vector>
#include <iostream>
#include <string>

#include "window_mgr.h"
#include "screen.h"

/*
Window_mgr::Window_mgr(ScreenIndex n){
    Screen default_screen(24,80,'b');
    std::vector<Screen> temp(n,default_screen);
    screens = temp;
}
*/
Window_mgr::Window_mgr(ScreenIndex n, Screen default_screen){
    std::vector<Screen> temp(n,default_screen);
    screens = temp;
}

std::ostream &Window_mgr::print(std::ostream &cout){
    for(Screen screen : screens){
        screen.print(cout)<<std::endl;
    }
    return cout;
}
void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}