class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int start = nums[0];
        int end = nums[0];
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i + 1] - 1){
                end = nums[i + 1];
            }else{
                string range;
                range += to_string(start)
                range.push_back('-');
                range.push_back('>');
                range += to_string(end);
                res.push_back(range);
                start = nums[i + 1];
                end = nums[i + 1];
            }
        }
        if(start != end){
            string range;
            range += to_string(start)
            range.push_back('-');
            range.push_back('>');
            range += to_string(end);
            res.push_back(range);
        }else{
            string range;
            range += to_string(end)
            res.push_back(range);
        }
        return res;
    }
};