class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0] == 0 ? 1 : 0;
        //if(nums.size() == nums[nums.size() - 1]) return 0;
        int max = INT_MIN, min = INT_MAX, sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
            sum += nums[i];
        }
        if(max == nums.size() && min != 0) return 0;
        if(max == nums.size() - 1) return max + 1;
        int completed_sum = ((max + min) * (nums.size() + 1)) / 2;
        return completed_sum - sum;
    }
};