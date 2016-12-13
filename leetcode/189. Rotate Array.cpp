class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(abs(k) > nums.size()){
            if(k < 0) k = -1 * (k % nums.size());
            else k %= nums.size();
        }
        if(k < 0){
            k = 0 - k;
            for(int i = 0; i < k; ++i){
                nums.erase(nums.begin());
                nums.push_back(0);
            }
            return;
        }
        else{
            vector<int> num_part_1(nums.begin(), nums.begin() + nums.size() - k); // first half
            vector<int> num_part_2(nums.begin() + nums.size() - k, nums.end()); // second half
            // insert first half at the end of the second half
            num_part_2.insert(num_part_2.end(), num_part_1.begin(), num_part_1.end());
            nums = num_part_2;
            return;
        }
    }
};