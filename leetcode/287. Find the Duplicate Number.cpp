// O(nlogn + n) solution, slow
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i + 1]) return nums[i];
        }
        return 0;
    }
};
// O(n) solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[abs(nums[i])] < 0){
                return abs(nums[i]);
            }else{
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
        }
        return 0;
    }
};