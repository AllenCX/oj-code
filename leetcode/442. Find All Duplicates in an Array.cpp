class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if(n <= 1) return res;
        for(int i = 0; i < n; ++i){
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};