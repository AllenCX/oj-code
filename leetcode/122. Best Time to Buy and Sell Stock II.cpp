// solution 1 by myself
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int flag = prices[1] > prices[0] ? 1 : -1; // -1 for downward, 1 for upward.
        int local_min = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i - 1] > prices[i] && flag != -1){
                res += prices[i - 1] - local_min;
                local_min = prices[i];
                flag = -1;
            }else if(prices[i - 1] > prices[i] && flag == -1){
                local_min = prices[i];
            }
            if(prices[i - 1] < prices[i] && flag != 1){
                flag = 1;
                continue;
            }else if(prices[i - 1] < prices[i] && flag == 1){
                continue;
            }
        }
        if(flag == 1) res += prices.back() - local_min;
        return res;
    }
};

// solution 2, greedy policy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            int diff = prices[i] - prices[i - 1];
            if(diff > 0) res += diff;
        }
        return res;
    }
};