#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy_nums = nums;
        sort(copy_nums.begin(), copy_nums.end());
        int i = 0;
        int j = nums.size()-1;
        
        while( i < j ){
            //std::cout<<i<<" "<<j<<std::endl;
            if( (copy_nums[i] + copy_nums[j]) < target ){
                ++i;
            } else if ( (copy_nums[i] + copy_nums[j]) > target ){
                --j;
            } else {
                break;
            }
        }
        int res_i,res_j;
        bool found_i=true;
        for (int k = 0; k < nums.size(); ++k){
            if (copy_nums[i] == nums[k] && found_i){
                res_i = k;
                found_i=false;
            }
            if (copy_nums[j] == nums[k]){
                res_j = k;
            }
        }
        return {res_i,res_j};
    }
};

int main(){
    vector<int> input = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(input,target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

