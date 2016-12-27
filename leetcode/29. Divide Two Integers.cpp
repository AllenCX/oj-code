class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        long long res = 0;
        long long plus = 1;
        int flag = 1;
        if(double(dividend) * double(divisor) < 0){
            flag = -1;
        }
        long long divid = labs(dividend);
        long long divis = labs(divisor);
        while(divid >= divis){
            long long tmp = divis;
            plus = 1;
            while(divid >= (tmp << 2)){
                tmp <<= 2;
                plus <<= 2;
            }
            divid -= tmp;
            res += plus;
        }
        return res * flag;
    }
};