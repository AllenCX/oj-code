class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ret;
        if(coins.size() == 0) return -1;
        vector<int> m(amount + 1, -1);
        m[0] = 0;
        for(int i = 1; i <= amount; ++i){
            long int min = 21474836479;
            //cout << "check2" << endl;
            for(int j = 0; j < coins.size(); ++j){
                //cout << "check3" << endl;
                if(i - coins[j] < 0) continue;
                long int ans = m[i - coins[j]] + 1;
                if(ans < min && ans > 0 &&i - coins[j] >= 0){
                    min = m[i - coins[j]] + 1;
                }
            }
            m[i] = min;
        }
        //cout << "check2" << endl;
        //for(int i = 1; i <= amount; ++i) cout << m[i] << " ";
        //cout << endl;
        if(m[amount] == 21474836479) return -1;
        else return m[amount];
    }
};