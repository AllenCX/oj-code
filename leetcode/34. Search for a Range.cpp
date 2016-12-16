class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int n = nums.size();
        vector<int> res(2, -1);
        while(left < right){
            int mid = (right + left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if(nums[left] != target) return res;
        else res[0] = left;
        right = n - 1;
        while(left < right){
            int mid = (right + left) / 2 + 1;
            if(nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        res[1] = right;
        return res;
    }
};