#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 && (nums[i] == nums[i-1])) continue;
            
            int target = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                
                int tmp = nums[l] + nums[r];
                if(tmp < target){
                    ++l;
                }else if(target < tmp){
                    --r;
                }else{
                    vector<int> tmp_vec;
                    tmp_vec.push_back(nums[i]);
                    tmp_vec.push_back(nums[l]);
                    tmp_vec.push_back(nums[r]);
                    ret.push_back(tmp_vec);
                    ++l;
                    --r;
                    while(nums[l] == nums[l-1]) ++l;
                    while(nums[r] == nums[r+1]) --r;
                }
            }
        }
        return ret;
    }
};
int	main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	return 0;
}