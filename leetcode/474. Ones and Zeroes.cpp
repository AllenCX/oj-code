class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < strs.size(); ++i){
            int countZeros = 0;
            int countOnes = 0;
            for(int j = 0; j < strs[i].size(); ++j){
                if(strs[i][j] == '0') ++countZeros;
                if(strs[i][j] == '1') ++countOnes;
            }
            for(int i = m; i >= countZeros; --i){
                for(int j = n; j >= countOnes; --j){
                    res[i][j] = max(res[i][j], res[i - countZeros][j - countOnes] + 1);
                }
            }
        }
        return res[m][n];
    }
};