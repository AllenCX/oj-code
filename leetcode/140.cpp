class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        string tmp_ret;
        if(s.size() == 0) return ret;
        if(wordDict.size() == 0) return ret;
        vector<bool> isSolution(s.size()+1, true);
        
        dfs(0, ret, tmp_ret, wordDict, s, isSolution);
        
        return ret;
    }
    void dfs(
        int depth, 
        vector<string> &ret, 
        string &tmp_ret, 
        unordered_set<string> wordDict, 
        string s, 
        vector<bool> &isSolution){
                
        if(depth == s.size()){
            ret.push_back(tmp_ret.substr(0, tmp_ret.size() - 1));
            return;
        }
        for(int i = depth; i <= s.size(); ++i){
            string str = s.substr(depth, i-depth+1);
            //cout << str << endl;
            if(wordDict.find(str) != wordDict.end()&&isSolution[i+1]){
                tmp_ret += str + " ";
                int beforeSize = ret.size();
                dfs(i+1, ret, tmp_ret, wordDict, s, isSolution);
                if(beforeSize == ret.size()){
                    isSolution[i+1] = false;
                }
                tmp_ret.resize(tmp_ret.size() - str.size() - 1);
            }
        }
    }
};