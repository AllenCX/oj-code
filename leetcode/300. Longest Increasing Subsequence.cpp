class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j <= i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

//nlogn version
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(res.size() == 0){
                res.push_back(nums[i]);
                continue;
            } 
            if(res.back() < nums[i]){
                res.push_back(nums[i]);
                continue;
            }else{
                int l = 0, r = res.size() - 1;
                while(l <= r){
                    int mid = l + (r - l) / 2;
                    if(res[mid] < nums[i]){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }       
                }
                res[l] = nums[i];
            }
        }
        return res.size();
    }
};
