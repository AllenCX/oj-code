class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp_ret;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return ret;
        dfs(0, ret, tmp_ret, nums, visited);
        return ret;
    }
    void dfs(int depth, vector<vector<int>> &ret, vector<int> &tmp_ret, vector<int> &nums, vector<bool> &visited){
        if(depth >= nums.size()){
            ret.push_back(tmp_ret);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] == false){
                if(i > 0&&nums[i] == nums[i-1]&&visited[i-1] == false) continue;
                visited[i] = true;
                tmp_ret.push_back(nums[i]);
                dfs(depth+1, ret, tmp_ret, nums, visited);
                tmp_ret.pop_back();
                visited[i] = false;
            }
        }
    }
};