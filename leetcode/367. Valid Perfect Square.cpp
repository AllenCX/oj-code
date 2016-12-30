class Solution {
public:
    bool isPerfectSquare(long long num) {
        if(num <= 1) return true;
        long long l = 1, r = num - 1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(mid*mid < num){
                l = mid + 1;
            }else if(mid*mid > num){
                r = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};