class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) {return 0;}
        int i = 0, j = height.size() - 1;
        int area = 0;
        while(i < j){
            int tmp = min(height[i], height[j]) * abs(j - i);
            if(tmp > area){
                area = tmp;
            }
            if(height[i] < height[j]){
                ++i;
            }else{
                --j;
            }
        }
        return area;
    }
};
