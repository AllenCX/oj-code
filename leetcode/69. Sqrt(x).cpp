class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return INT_MIN;
        if(x == 0 || x == 1) return x;
        int l = 1, r = x - 1;
        while(l <= r){
            double mid = l + ((r - l) / 2);
            if(mid * mid > x){
                r = mid - 1;
            }else if(mid * mid < x){
                l = mid + 1;    
            }else{
                return mid;
            }
        }
        return r;
    }
};