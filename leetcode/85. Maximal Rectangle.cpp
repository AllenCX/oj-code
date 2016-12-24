class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size() + 2, 0);
        int index = 0;
        int area = 0;
        for(int i = 0; i < matrix.size(); ++i){
            stack<int> st;
            st.push(0);
            for(int j = 1; j < heights.size(); ++j){
                if(matrix[i][j - 1] == '1'){
                    ++heights[j];
                }else{
                    heights[j] = 0;
                }
                while(heights[j] < heights[index = st.top()]){
                    st.pop();
                    area = max(area, heights[index] * (j - st.top() - 1));
                }
                st.push(j);
            }
        }
        return area;
    }
};