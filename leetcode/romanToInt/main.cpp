#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;
using std::map;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> symbolConvert = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num = 0;
        for(auto beg = s.begin(), end = s.end(); beg!= end; ++beg){
            auto temp = beg;
            ++temp;
            if( temp != s.end() && symbolConvert[*temp] > symbolConvert[*beg]){
                num += (symbolConvert[*temp]-symbolConvert[*beg]);
                ++beg;

            } else {
                num += symbolConvert[*beg];
            }
        }
        return num;
    }
};


int main(){
    string x = "MCMXCIV";
    Solution s;
    cout << s.romanToInt(x) << endl;
    return 0;
}
