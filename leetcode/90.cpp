class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp_ret;
        if(nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());
        dfs(0, ret, tmp_ret, nums);
        return ret;
    }
    void dfs(int depth, vector<vector<int>> &ret, vector<int> tmp_ret, vector<int> nums){
        ret.push_back(tmp_ret);
        for(int i = depth; i < nums.size(); ++i){
            tmp_ret.push_back(nums[i]);
            dfs(i+1, ret, tmp_ret, nums);
            tmp_ret.pop_back();
            while(i < nums.size() && nums[i] == nums[i+1]) ++i;
        }
        return;
    }
};