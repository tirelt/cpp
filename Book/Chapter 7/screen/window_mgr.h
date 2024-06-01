#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "screen.h"

class Window_mgr {
    public: 
        // location ID for each screen on the window
        using ScreenIndex = std::vector<Screen>::size_type;

        Window_mgr() = default;
        //Window_mgr(ScreenIndex n);
        Window_mgr(ScreenIndex n, Screen default_screen = Screen(24,80,'b'));

        Screen &get_screen(ScreenIndex n) {return screens[n];}
        std::ostream &print(std::ostream &cout);
        void clear(ScreenIndex);
        // add a Screen to the window and returns its index
        ScreenIndex addScreen(const Screen&);
        
    private:
        // Screens this Window_mgr is tracking
        // by default, a Window_mgr has one standard sized blank Screen
        std::vector<Screen> screens{Screen(24,80,'.')};
};

#endif