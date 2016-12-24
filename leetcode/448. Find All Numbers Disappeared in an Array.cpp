class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int> res;
         // make the element nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]
         for(int i = 0; i < nums.size(); ++i){
             if(nums[abs(nums[i]) - 1] > 0){
                 nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
             }
         }
         // if there is an element is not negative, then add the position number to result
         // if element x is appeared in the list, then nums[x - 1] has to be negative
         for(int i = 0; i < nums.size(); ++i){
             if(nums[i] > 0){
                 res.push_back(i + 1);
             }
         }
         return res;
    }
};