class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n <= 2) return n;
        int last = -1, front = 0;
        int tmp_count = 1;
        nums.push_back(INT_MAX); // guard
        while(front < n){ // because of the adding of guard, nums.size() is n now. 
            if(nums[front + 1] == nums[front]){
                ++tmp_count;
                if(tmp_count <= 2){
                    ++last;
                    nums[last] = nums[front];
                }
            }else if(nums[front + 1] != nums[front]){
                res += tmp_count > 2 ? 2 : tmp_count;
                tmp_count = 1;
                ++last;
                nums[last] = nums[front];
            }
            ++front;
        }
        res += tmp_count > 2 ? 2 : tmp_count;
        //if(tmp_count >= 2)
        return res-1;
    }
};