class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> max_heap(nums.begin(), nums.end());
        int max = max_heap.top();
        int dis_n = 0;
        int res = INT_MIN;
        while(dis_n < 3 && !max_heap.empty()){
            if(max_heap.top() == res){
                max_heap.pop();
                continue;
            }else{
                res = max_heap.top();
                max_heap.pop();
                ++dis_n;    
            }
        }
        if(dis_n < 3) return max;
        else return res;
    }
};