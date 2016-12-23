class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        int index;
        for(int i = 1; i < heights.size(); ++i){
            index = st.top();
            while(heights[i] < heights[index]){
                st.pop();
                res = max(res, heights[index] * (i - st.top() - 1));
                index = st.top();
            }
            st.push(i);
        }
        return res;
    }
};