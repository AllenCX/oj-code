class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int k = 0;
        if(nums.size() == 0) return 0;
        int n = nums.size();
        while(sum < s && k < n){
            sum += nums[k];
            ++k;
        }
        if(sum < s && k == n) return 0; // sum of all elements less than s;
        nums.push_back(0);
        int res = k + 1;
        for(int i = k; i < n + 1; ++i){
            while(sum >= s){
                sum -= nums[i - k];
                --k;
            }
            res = k + 1;
            if(k == 0) break;
            sum = sum + nums[i] - nums[i - k];
        }
        return res;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int start = 0, min_len = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            while(sum >= s){
                min_len = min(min_len, i - start + 1);
                sum -= nums[start];
                ++start;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};