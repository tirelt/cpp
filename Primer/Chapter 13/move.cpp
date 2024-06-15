#include <utility>
#include <string>
#include <algorithm>
#include <vector>


// the compiler will synthesize the move operations for X and hasX
struct X {
    int i; // built-in types can be moved
    std::string s; // string defines its own move operations
};
struct hasX {
    X mem; // X has synthesized move operations
};
X x, x2 = std::move(x); // uses the synthesized move constructor
hasX hx, hx2 = std::move(hx); // uses the synthesized move constructor


class Foo {
    public:
        Foo sorted() &&; // may run on modifiable rvalues
        Foo sorted() const &; // may run on any kind of Foo
        // other members of Foo
private:
    std::vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}
// this object is either const or it is an lvalue; either way we can’t sort in place
Foo Foo::sorted() const & {
    Foo ret(*this); // make a copy
    sort(ret.data.begin(), ret.data.end()); // sort the copy
    return ret; // return the copy
}
