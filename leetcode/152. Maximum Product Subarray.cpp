class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int max_Product = nums[0];
        int min_Product = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int t = max_Product;
            max_Product = max(max(min_Product * nums[i], max_Product * nums[i]), nums[i]);
            min_Product = min(min(min_Product * nums[i], t * nums[i]), nums[i]);
            res = max(res, max_Product);
        }
        return res;
    }
};