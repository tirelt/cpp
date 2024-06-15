#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

//function objects
struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

class PrintString {
    public:
        PrintString(ostream &o, char &c):os(o), sep(c) { }
        void operator()(const string &s) const { os << s << sep; }
    private:
        ostream &os; // stream on which to write
        char &sep; // character to print after each output
};

int main(){
    int i = -42;
    absInt absObj; // object that has a function-call operator
    int ui = absObj(i); // passes i to absObj.operator()
    char sep = '-';
    PrintString pinter(cout,sep);
    sep = '/';
    pinter("Theo");
}