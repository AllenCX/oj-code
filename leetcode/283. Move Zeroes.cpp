#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] != 0){
                nums[j] = nums[i];
                ++j;
            }
        }
        for(; j < n; ++j){
            nums[j] = 0;
        }
    }
};