class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for(int i = 0; i < nums.size(); ++i){
            left = max(left, nums[i]);
            right += nums[i];
        }
        while(left < right){
            long long mid = left + (right - left) / 2;
            if(canSplit(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    bool canSplit(vector<int> &nums, int m, int sum){
        int cnt = 1;
        int curSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            curSum += nums[i];
            if(curSum > sum){
                curSum = nums[i];
                ++cnt;
                if(cnt > m) return false;
            }
        }
        return true;
    }
};