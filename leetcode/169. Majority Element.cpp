class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();  
        int major = 0, count = 0;
        for(int i = 0; i < n; ++i){
            if(!count){
                major = nums[i];
                count = 1;
            }else{
                count += (major == nums[i]) ? 1 : -1;
            }
        }
        return major;
    }
};