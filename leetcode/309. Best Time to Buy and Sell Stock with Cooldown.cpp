/* 
 https://discuss.leetcode.com/topic/30421/share-my-thinking-process/2
 Very ingenious solution
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, prev_buy = 0, prev_sell = 0;
        for(int i = 0; i < prices.size(); ++i){
            prev_buy = buy;
            buy = max(prev_sell - prices[i], prev_buy);
            prev_sell = sell;
            sell = max(prev_buy + prices[i], prev_sell);
        }
        return sell;
    }
};