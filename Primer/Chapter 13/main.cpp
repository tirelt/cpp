#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <functional>
#include <memory>
#include <map>
#include <set>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0),use(new std::size_t(1)) { }
        // each HasPtr has its own copy of the string to which ps points
        HasPtr(const HasPtr &p):ps(new std::string(*p.ps)), i(p.i),use(p.use){++*use;}
        HasPtr& operator=(const HasPtr &);
        ~HasPtr() { delete ps; }
    private:
        std::string *ps;
        int i;
        std::size_t *use;
};
/*
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps); // copy the underlying string
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
}
*/
HasPtr::~HasPtr()
{
    if (--*use == 0) { // if the reference count goes to 0
        delete ps; // delete the string
        delete use; // and the counter
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0) { // then decrement this object’s counter
        delete ps; // if no other users
        delete use; // free this object’s allocated members
    }
    ps = rhs.ps; // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this; // return this object
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i); // swap the int members
}