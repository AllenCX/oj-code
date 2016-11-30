class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        if(target < nums[0]) return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i < nums[j]) break;
                if(i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp.back();
    }
};