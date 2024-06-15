#include <string>
#include <iostream>
#include <map>
#include <deque>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::deque;

class Solution {
public:
    string longestPalindrome(string s) {
        deque<char> current;
        string longest;
        string::iterator beg =s.begin(),end=s.end(),before_beg = beg;
        --before_beg;        
        bool advance1=false;
        for(string::iterator ite1 = beg,ite2 = beg;ite1!=end && ite2!=end; advance1?++ite2:++ite1){
            advance1=!advance1;
            //cout << "start " <<*ite1 << " " << *ite2 << endl;
            if(*ite1==*ite2){
                current = {};
                for(string::iterator ite3 = ite1,ite4 = ite2;ite3!=before_beg&&ite4!=end&&*ite3==*ite4;--ite3,++ite4){
                    //cout <<*ite3 << " " << *ite4 << endl;
                    if(ite3==ite4)
                        current = {*ite1};
                    else{
                        current.push_back(*ite3);
                        current.push_front(*ite4);
                    }
                }
            }
            if(current.size() > longest.size()){
                longest = string(current.begin(),current.end());
                //cout << "longest: " << current.size() << " " << longest << endl;
            }
        }
        return longest;
    }
};

int main(){
    string input("abbbbbbb");
    Solution s;
    cout << s.longestPalindrome(input) << endl;
    return 0;
}