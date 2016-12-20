[0]
[2,1,1,2,3,1,0,4]
[1,2,3,4,5]

class Solution_dp { // TLE
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX - 100);
        dp[0] = 0;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = i; j >=0; --j){
                if(i - j <= nums[j]){
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[nums.size() - 1]; // or return dp.back();
    }
};

class Solution_2{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(nums.size(), INT_MAX - 100);
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            if(n - i <= nums[i]) return dp[i] + 1;
            for(int j = 1; j <= nums[i]; ++j){
                if(i + j > n - 1) break;
                if(i != 0) dp[i + j] = min(dp[i] + 1, dp[i + j]);
                if(i == 0) dp[i + j] = dp[i] + 1;
            }
            //i += nums[i];
        }
        return dp.back();
    }
};
// greedy solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, curFarest = 0, curEnd = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            curFarest = max(curFarest, i + nums[i]);
            if(i == curEnd){
                ++res;
                curEnd = curFarest;
            }
        }
        return res;
    }
};