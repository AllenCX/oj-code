class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0;
        int count_x = 0, count_y = 0;
        for(auto i : nums){
            if(x == i) ++count_x;
            else if(y == i) ++count_y;
            else if(!count_x) x = i, count_x = 1;
            else if(!count_y) y = i, count_y = 1;
            else{
                --count_x;
                --count_y;
            }
        }
        count_x = 0; count_y = 0;
        for(auto i : nums){
            if(x == i) ++count_x;
            else if(y == i) ++count_y;
        }
        vector<int> res;
        if(count_x > nums.size() / 3) res.push_back(x);
        if(count_y > nums.size() / 3) res.push_back(y);
        return res;
    }
};