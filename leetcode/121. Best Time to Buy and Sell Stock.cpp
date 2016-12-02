class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0, global_min = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            global_min = min(global_min, prices[i]);
            res = max(res, prices[i] - global_min);
        }
        return res;
    }
};