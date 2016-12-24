class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //int res;
        if(matrix.size() == 0) return 0;
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_len = 0;
        for(int i = 0; i < matrix.size(); ++i){
            res[i][0] = matrix[i][0] - '0';
            max_len = max(res[i][0], max_len);
        }
        for(int j = 0; j < matrix[0].size(); ++j){
            res[0][j] = matrix[0][j] - '0';
            max_len = max(res[0][j], max_len);
        }
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '1'){
                    res[i][j] = min(res[i - 1][j - 1], min(res[i - 1][j], res[i][j - 1])) + 1;
                    max_len = max(max_len, res[i][j]);
                }
            }
        }
        return max_len * max_len;
    }
};