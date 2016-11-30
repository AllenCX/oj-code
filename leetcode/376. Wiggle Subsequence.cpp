class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int res = 1;
        int flag = 0; // -1 => down or equal, 1 => up
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] < nums[i + 1] && flag != 1){
                ++res;
                flag = 1;
            }else if(nums[i] > nums[i + 1] && flag != -1){
                ++res;
                flag = -1;
            }else if(nums[i] == nums[i + 1]){
                continue;
            }
        }
        return res;
    }
};