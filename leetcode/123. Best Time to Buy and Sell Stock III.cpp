// TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        if(prices.size() == 2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        int res = INT_MIN;
        for(int i = 1; i < prices.size() - 1; ++i){
            res = max(res, solve(prices, 0, i) + solve(prices, i, prices.size() - 1));
        }
        return res;
    }
    int solve(vector<int> &prices, int l, int r){
        int res = INT_MIN;
        int global_min = INT_MAX;
        for(int i = l; i <= r; ++i){
            global_min = min(global_min, prices[i]);
            res = max(res, prices[i] - global_min);
        }
        return res;
    }
};

// AC solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        if(prices.size() == 2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        vector<int> left(prices.size(), 0);
        int left_min = prices[0];
        int left_max = 0;
        for(int i = 1; i < prices.size(); ++i){
            left_min = min(left_min, prices[i]);
            left_max = max(left_max, prices[i] - left_min);
            left[i] = left_max;
        }
        int right_max_price = prices[prices.size() - 1];
        int right_max_profit = 0;
        int res = left[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0; --i){
            right_max_price = max(right_max_price, prices[i]);
            right_max_profit = max(right_max_profit, right_max_price - prices[i]);
            //right[i] = right_max;
            res = max(left[i] + right_max_profit, res);
        }
        return res;
    }
};