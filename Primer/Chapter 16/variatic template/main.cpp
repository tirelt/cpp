#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template<typename T> ostream &print(ostream &os, const T &t)
{
    return os << t <<endl; // no separator after the last element in the pack
}
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args> ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", "; // print the first argument
    return print(os, rest...); // recursive call; print the other arguments
}

int main(){
    string s("tirel");
    int i(10);
    double d(3.14);
    print(cout,s,"theo",i,d);
    return 0;
}