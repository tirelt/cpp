#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = std::to_string(x);
        string x_reverse_str = x_str;
        reverse(x_reverse_str.begin(), x_reverse_str.end());
        return x_str==x_reverse_str;
    }
};

int main(){
    int x = 121;
    Solution s;
    cout << s.isPalindrome(x) << endl;
    return 0;
}

