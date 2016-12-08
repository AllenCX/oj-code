// new version of POW require us to handle overflow.
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1; 
        if(x == -1) return n % 2 == 0 ? 1 : -1;
        if(n == 0) return 1;
        if(n < 0){ 
            if(n == INT_MIN){
                return 0;
            }
            n = -n;
            x = 1 / x;
        }
        double r = pow(x, n / 2);
        if(n % 2 == 0){
            return r * r;
        }else{
            return x * r * r;
        }
    }
};