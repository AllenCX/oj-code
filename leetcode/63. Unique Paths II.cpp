class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        if(height == 0) return 0;
        
        int width = obstacleGrid[0].size();
        if(height == 1 && width == 0) return 1;
        
        if(obstacleGrid[0][0] == 1 && height == 1 && width == 1) return 0;
        int dp[height][width];
        bool flag = false;
        dp[0][0] = 1;
        //if()
        if(obstacleGrid[height - 1][width - 1] == 1) return 0;
        for(int i = 0; i < height; ++i){
            if(obstacleGrid[i][0] == 1) flag = true;
            if(flag == false) dp[i][0] = 1;
            else dp[i][0] = 0;
        }
        flag = false;
        for(int j = 0; j < width; ++j){
            if(obstacleGrid[0][j] == 1) flag = true;
            if(flag == false) dp[0][j] = 1;
            else dp[0][j] = 0;
        }
        for(int i = 1; i < height; ++i){
            for(int j = 1; j < width; ++j){
                dp[i][j] = (1 - obstacleGrid[i - 1][j]) * dp[i - 1][j] + (1 - obstacleGrid[i][j - 1]) * dp[i][j - 1];
            }
        }
        return dp[height - 1][width - 1];
    }
};