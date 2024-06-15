#include <functional>
#include <map>
#include <string>

using std::function;
using std::map;
using std::string;

// ordinary function
int add(int i, int j) { return i + j; }

// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j) { return i % j; };
// function-object class
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main(){
    // int(int,int) call signature not type
    function<int(int, int)> f1 = add; // function pointer
    function<int(int, int)> f2 = divide(); // object of a function-object class
    function<int(int, int)> f3 = [](int i, int j) { return i * j; }; //lambda

    map<string, function<int(int, int)>> binops = {
        {"+", add}, // function pointer
        {"-", std::minus<int>()}, // library function object
        {"/", divide()}, // user-defined function object
        {"*", [](int i, int j) { return i * j; }},// unnamed lambd
        {"%", mod} }; // named lambda object
}