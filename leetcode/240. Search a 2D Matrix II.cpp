class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int nRow = matrix.size(), nCol = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[nRow - 1][nCol - 1]){
            return false;
        }
        int row = 0, col = nCol - 1;
        while(col >= 0 && row <= nRow - 1){
            if(matrix[row][col] < target){
                ++row;
            }else if(matrix[row][col] > target){
                --col;
            }else{
                return true;
            }
        }
        return false;
    }
};