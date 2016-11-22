class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp_ret;
        if(s.size() == 0) return ret;
        dfs(0, ret, tmp_ret, s);
        return ret;
    }
    void dfs(int depth, vector<vector<string>> &ret, vector<string> &tmp_ret, string s){
        if(depth == s.size()){
            ret.push_back(tmp_ret);
            return;
        }
        for(int i = depth; i < s.size(); ++i){
            if(isPalindrome(s, depth, i)){
                tmp_ret.push_back(s.substr(depth, i-depth+1));
                dfs(i+1, ret, tmp_ret, s);
                tmp_ret.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int l, int r){
        int len = s.size();
        while(l < r){
            if(s[r] == s[l]){
                --r;
                ++l;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};