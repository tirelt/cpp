#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::log;
using std::exp;
using std::abs;

class Solution {
public:
    double myPow_rec(double x, int n) {
        if(n == 0)
            return 1;
        else if(n==1)
            return x;
        else if(n>1)
            return x*myPow(x,n-1);
        else
            return 1/myPow(x,-n);
    }
    double myPow(double x, int n) {
        return (x<0?(n%2==0?1:-1):1)*exp(n*log(abs(x)));  
    }
};

int main(){
    Solution s;
    cout << s.myPow(2,10) << endl;
    cout << s.myPow(2.1,3) << endl;
    cout << s.myPow(2,-2) << endl;
    cout << s.myPow(-2,2) << endl;
}