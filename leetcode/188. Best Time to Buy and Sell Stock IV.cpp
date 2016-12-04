class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2) return 0;
        if(k >= prices.size()) return allProfit(prices);
        vector<vector<int>> global(prices.size(), vector<int>(k + 1, 0));
        vector<vector<int>> local(prices.size(), vector<int>(k + 1, 0));
        for(int i = 1; i < prices.size(); ++i){
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <=k; ++j){
                local[i][j] = max(global[i - 1][j - 1] + max(0, diff), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[prices.size() - 1][k];
    }
    
    int allProfit(vector<int> &prices){
        int res = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            int diff = prices[i + 1] - prices[i];
            if(diff > 0){
                res += diff;
            }
        }
        return res;
    }
};