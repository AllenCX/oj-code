class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle[0].size() == 0) return 0;
        int sum[triangle.size()]; // dp[0] is the answer
        int row = triangle.size();
        for(int i = row - 1; i >= 0; --i){
            int col = triangle[i].size();
            for(int j = 0; j < col; ++j){
                if(i == row - 1){
                    sum[j] = triangle[i][j];
                }else{
                    sum[j] = min(sum[j], sum[j + 1]) + triangle[i][j];    
                }
            }
        }
        return sum[0];
    }
};