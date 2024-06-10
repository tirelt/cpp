#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::bind;
using namespace std::placeholders;

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

int main(){
    ostream &os = cout;
    vector<string> words{"theo","tirel"};
    string c("/");
    for_each(words.begin(), words.end(),[&os, c](const string &s) { os << s << c; });
    os << endl;
    for_each(words.begin(), words.end(),bind(print, ref(os), _1, ' ')); 
    os << endl;
    return 0;
}