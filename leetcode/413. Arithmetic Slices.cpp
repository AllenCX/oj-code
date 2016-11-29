// Runtime: 3ms, beats only 7%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len == 0) return 0;
        int ret = 0;
        int nums[len + 1];
        for(int i = 0; i <= len; ++i){
            if(i < 3) nums[i] = 0;
            else{
                nums[i] = nums[i - 1] + i - 2;
            }
        }
        int len_count = 0;
        int diff = INT_MAX;
        for(int i = 0; i < len - 1; ++i){
            if(A[i] - A[i + 1] != diff){
                ret += nums[len_count + 1];
                len_count = 1;
                diff = A[i] - A[i + 1];
            }else{
                ++len_count;
            }
        }
        ret += nums[len_count + 1];
        return ret;
    }
};

// Solution 2
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len == 0) return 0;
        int ret = 0;
        int len_count = 0;
        for(int i = 0; i < len - 2; ++i){
            if(A[i] - A[i + 1] == A[i + 1] - A[i + 2]){
                len_count += 1;
                ret += len_count;
            }else{
                len_count = 0;
            }
        }
        return ret;
    }
};