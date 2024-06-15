#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string s("some string");
    // process characters in s until we run out of characters or we hit a whitespace
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
        *it = toupper(*it); // capitalize the current character
    };  
    vector<string> text{"theo","tirel","","yo"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it){
        cout << *it << endl;
    };
    return 0;
};