// binary search solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            if(nums[mid] > nums[mid + 1]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return 0;
    }
};
// sequential search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        for(int i = 0; i < nums.size() - 2; ++i){
            if(nums[i + 1] > nums[i] && nums[i + 1] > nums[i + 2]) return i + 1;
        }
        return 0;
    }
};