class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 && nums[0] == 0) return false;
        if(n == 1 && nums[0] != 0) return true;
        int cur = n - 1;
        int i = n - 2;
        while(i >= 0){
            while(i >= 0 && nums[i] < cur - i){
                --i;
            }
            cur = i;
            --i;
        }
        return cur == 0;
    }
};