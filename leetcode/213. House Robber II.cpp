#include <vector>
#include <iostream>
using namespace std;
// runtime error, do not know why
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1], nums[0]);
        int a = house_rob(nums, 0, nums.size() - 2);
        int b = house_rob(nums, 1, nums.size() - 1);
        cout << a << "_" << b << endl;
        return max(a, b);
    }
    int house_rob(vector<int> nums, int left, int right){
        vector<int> dp(right - left + 1, 0);
        for(int i = left; i <= right; ++i){
            cout << nums[i] << " " << i << endl;
            if(i == left) dp[left] == nums[left];
            else if(i == left + 1) dp[left + 1] = max(nums[left], nums[left + 1]);
            else{
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
        }
        cout << dp.back();
        cout << endl;
        return dp.back();
    }
};

// AC solution
class Solution {
public:
    int robOrigin(vector<int> &nums){
        int a = 0, b = 0, res = 0;
        // a for dp[i - 1], b for dp[i - 2]
        for(int i = 0; i < nums.size(); ++i){
            res = max(a, b + nums[i]);
            b = a;
            a = res;
        }
        return res;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1], nums[0]);
        vector<int> dp_1(nums.begin(), nums.end() - 1);
        vector<int> dp_2(nums.begin() + 1, nums.end());
        return max(robOrigin(dp_1), robOrigin(dp_2));
    }
};