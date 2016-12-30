// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)){
            return 1;
        }
        int l = 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isBadVersion(mid) == true && isBadVersion(mid - 1) == false){
                return mid;
            }
            if(isBadVersion(mid) == false){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};