class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> index(nums.size(), -1);
        vector<int> ans;
        int max_index = 0, max_dp = 0;
        if(nums.size() == 0) return ans;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    index[i] = j;
                }
            }
            if(max_dp < dp[i]){
                max_dp = dp[i];
                max_index = i;
            }
        }
        for(int i = max_index; i != -1;i = index[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};