class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        if(nums.size() == 3) return ret;
        sort(nums.begin(), nums.end());
        int l, r;
        for(int i = 0; i < n - 2; ++i){
            l = i + 1;  
            r = n - 1;
            while(l < r){
                if(abs(target - ret) > abs(target - nums[i] - nums[l] - nums[r])){
                    ret = nums[i] + nums[l] + nums[r];
                }
                if(target < nums[i] + nums[l] + nums[r]){
                    --r;
                }else{
                    ++l;
                }
            }
        }
        return ret;
    }
};