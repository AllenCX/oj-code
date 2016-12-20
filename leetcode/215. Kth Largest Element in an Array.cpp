class cmp{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<int> q(nums.begin(), nums.end());
        --k;
        while(k && !q.empty()){
            q.pop();
            --k;
        }
        return q.top();
    }
};