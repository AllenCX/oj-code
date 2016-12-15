class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        build(matrix, res, 0, matrix.size(), matrix[0].size());
        return res;
    }
    void build(vector<vector<int>>& matrix, vector<int> &res, int rank, int height, int width){
        if(height == 0) return;
        int size = height * width;
        if(size == 0) return;
        if(width == 1){
            for(int i = rank; i < rank + height; ++i){
                res.push_back(matrix[i][rank]);
            }          
            return;
        }
        if(height == 1){
            for(int i = rank; i < rank + width; ++i){
                res.push_back(matrix[rank][i]);
            }
            return;
        }
        for(int j = rank; j < rank + width - 1; ++j){
            res.push_back(matrix[rank][j]);
        }
        for(int j = rank; j < rank + height - 1; ++j){
            res.push_back(matrix[j][rank + width - 1]);
        }
        for(int j = rank + width - 1; j >= rank + 1; --j){
            res.push_back(matrix[rank + height - 1][j]);
        }
        for(int j = rank + height - 1; j >= rank + 1; --j){
            res.push_back(matrix[j][rank]);
        }
        ++rank;
        height -= 2;
        width -= 2;
        build(matrix, res, rank, height, width);
        return;
    }
};