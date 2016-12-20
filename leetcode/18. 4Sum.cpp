class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 2; ++j){// 3 sum
                if(j > i + 1&& nums[j] == nums[j - 1]) continue;
                int small_target = target - nums[i] - nums[j];
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    int tmp = nums[l] + nums[r];
                    if(tmp < small_target){
                        ++l;
                    }else if(tmp > small_target){
                        --r;
                    }else{
                        vector<int> tmp_res;
                        tmp_res.push_back(nums[i]);
                        tmp_res.push_back(nums[j]);
                        tmp_res.push_back(nums[l]);
                        tmp_res.push_back(nums[r]);
                        res.push_back(tmp_res);
                        ++l;
                        --r;
                        while(nums[l] == nums[l - 1]) ++l;
                        while(nums[r] == nums[r + 1]) --r;
                    }
                }
            } 
        }
        return res;
    }
};