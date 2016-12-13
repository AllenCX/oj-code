class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return false;
        unordered_map<int, bool> mp;
        for(auto n : nums){
            if(mp.find(n) == mp.end()) mp[n] = true;
            else return true;
        }
        return false;
    }
};