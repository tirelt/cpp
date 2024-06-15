#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    std::ofstream out("output");
    std::ostream_iterator<string> outIter(out,"\n");
    string line;
    while (getline(cin,line)){
        outIter = line;
    }
    return 0;
}