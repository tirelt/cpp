#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){

    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line))
        cout << line << endl;
    string s("Hello World!!!");
    // punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
    decltype(s.size()) punct_cnt = 0;
    // count the number of punctuation characters in s
    for (auto c : s) // for every char in s
        if ( ispunct(c) ) // if the character is punctuation
            ++punct_cnt; // increment the punctuation counter
    cout << punct_cnt  << " punctuation characters in " << s << endl;
    return 0;
};