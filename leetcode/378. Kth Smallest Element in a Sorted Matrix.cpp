class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        int l = matrix[0][0], r = matrix[nRow - 1][nCol - 1];
        int mid = 0;
        while(l < r){
            mid = l + (r - l) / 2;
            int num = 0;
            for(int i = 0; i < nRow; ++i){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if(num < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
