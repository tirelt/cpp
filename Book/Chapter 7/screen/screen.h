#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
//#include "window_mgr.h"

class Screen {
    friend class Window_mgr;
    //friend void Window_mgr::clear(ScreenIndex);
    public:
        // Type member
        typedef std::string::size_type pos;

        // Constructor
        Screen() = default; // needed because Screen has another constructor cursor initialized to 0 by its in-class initializer
        Screen(pos ht, pos wd, char c) : height(ht), width(wd),contents(ht * wd, c) { }
        Screen(std::istream &cin);
        //Member functions
        char get() const // get the character at the cursor
            { return contents[cursor]; } // implicitly inline
        char get(pos ht, pos wd) const; 
        Screen &move(pos r, pos c);  // explicitly inline
        void some_member() const;
        Screen &set(char);
        Screen &set(pos, pos, char);
        std::ostream &print( std::ostream &cout) {return cout << contents;}
        
    private:
        // Data member
        pos cursor = 0;
        pos height = 0;
        pos width = 0;
        std::string contents;
        mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r, pos c) // we can specify inline on the definition
{
    pos row = r * width; // compute the row location
    cursor = row + c; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}

#endif