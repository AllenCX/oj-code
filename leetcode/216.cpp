class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> tmp_ret;
        dfs(1, ret, tmp_ret, k, n);
        return ret;
    }
    void dfs(int depth, vector<vector<int>> &ret, vector<int> &tmp_ret, int k, int n){
        if(n < 0 || tmp_ret.size() > k) return;
        if(n == 0 && tmp_ret.size() == k){
            ret.push_back(tmp_ret);
            return;
        }
        for(int i = depth; i < 10; ++i){
            tmp_ret.push_back(i);
            dfs(i+1, ret, tmp_ret, k, n-i);
            tmp_ret.pop_back();
        }
    }
};