#include <vector>
#include <iostream>
using namespace std;
class NumMatrix {
    vector<vector<int> > dp;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        int height = matrix.size();
class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int height = matrix.size();
        int width = height == 0?0:matrix[0].size();
        dp.resize(height, vector<int>(width, 0));
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if(i == 0 && j == 0) dp[i][j] = matrix[i][j];
                else if(i == 0 && j != 0) dp[i][j] = dp[i][j - 1] + matrix[i][j];
                else if(i != 0 && j == 0) dp[i][j] = dp[i - 1][j] + matrix[i][j];
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return dp[row2][col2];
        else if(row1 != 0 && col1 == 0) return dp[row2][col2] - dp[row1 - 1][col2];
        else if(row1 == 0 && col1 != 0) return dp[row2][col2] - dp[row2][col1 - 1];
        else{
            return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }
        
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);