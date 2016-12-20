class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() - 1){
            if(nums[i + 1] < nums[i]) break;
            else ++i;
        }
        if(i == nums.size() - 1) return nums[0];
        reverse(nums.begin(), nums.begin() + i);
        reverse(nums.begin() + i + 1, nums.end());
        return nums.back();
    }
};