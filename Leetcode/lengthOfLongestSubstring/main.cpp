#include <string>
#include <unordered_set>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //cout << s << endl;
        unsigned ret(0);
        unsigned current(0);
        for(auto beg = s.cbegin();beg != s.cend() && ret < s.cend()-beg; ++beg){
            unordered_set<char> currentSet;
            auto curr = beg;
            while(curr != s.cend()){
                auto resInsert = currentSet.insert(*curr);
                //cout << *curr;
                if (!resInsert.second){
                    break;
                }
                ++curr;
            }
            string substring(beg,curr);
            //cout << substring << endl;
            current = currentSet.size();
            ret = ret < current ? current : ret;
        }
        //cout << endl;
        return ret;        
    }
    
};

int main(){
    string input = "t4s123gf4w15d21/5%15";
    Solution s;
    cout << s.lengthOfLongestSubstring(input) << endl;
    return 0;
}

