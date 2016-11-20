class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        int perm = 1;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i){
            nums[i] = (i + 1);
            perm = perm * (i + 1);
        }
        --k;
        int choosed;
        for(int i = 0; i < n; ++i){
            perm = perm / (n - i);
            choosed = k / perm;
            ret.push_back('0' + nums[choosed]);
            
            for(int j = choosed; j < n - i; ++j){
                nums[j] = nums[j+1];
            }
            
            k = k % perm;
        }
        return ret;
    }
    /*
    DFS: ETL
    int count = 0;
    string getPermutation(int n, int k) {
        string tmp_ret;
        string ret;
        vector<bool> visited(n, 0);
        dfs(0, tmp_ret, ret, visited, n, k);
        //for(int i = 0; i < ret.size(); ++i) cout << ret[i] << endl;
        return ret;
    }
    void dfs(int depth, string &tmp_ret, string &ret, vector<bool> &visited, int n, int k){
        if(depth == n){
            ++count;
            if(count == k){
                ret = tmp_ret;
                return;   
            }
        }
        for(int i = 0; i < n; ++i){
            if(visited[i] == 0){
                visited[i] = 1;
                //cout << "v" << i << " is false->true" << endl;
                tmp_ret.push_back('1' + i);
                dfs(depth+1, tmp_ret, ret, visited, n, k);
                tmp_ret.pop_back();
                visited[i] = 0;
            }else{
                continue;
            }
        }
    }
    */
};