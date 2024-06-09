#include <type_traits>

template <typename It> auto fcn2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type
{
    // process the range
    return *beg; // return a copy of an element from the range
}

int main(){
    int a = 5;
    int & r = a;
    typename std::remove_reference<decltype(r)>::type c;
    return 0;
}