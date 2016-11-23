#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) sum += nums[i];
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        // initiate marigin value
        for(int i = 0; i < nums.size(); ++i){
            for(int j = target; j >= nums[i]; --j){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp.back();
    }
};
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) sum += nums[i];
        if(sum % 2 == 1) return false;
        bitset<5001> bits(1);
        for(int i = 0; i < nums.size(); ++i)
            bits |= bits << nums[i];
        return bits[sum >> 1];
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
    int n[] = {1,4,5,5,5};
	vector<int> v(n, n + 5);
    cout << s.canPartition(v) << endl;
    return 0;
}
