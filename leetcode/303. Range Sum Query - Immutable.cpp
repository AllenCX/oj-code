class NumArray {
    int n;
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        dp.resize(n + 1, 0);
        for(int i = 0; i < n; ++i){
            if(i == 0) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
        }
    }
    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        else return dp[j] - dp[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);