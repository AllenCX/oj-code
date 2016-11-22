class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> ret(n);
        ret[0] = 10;
        int count = 1;
        int total = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0) {
                count *= 9;
                total += 10;
                ret[i] = 10;
            }
            else{
                count *= 10 - i;
                total += count;
                ret[i] = total;
            }
        }
        return ret[n-1];
    }
};