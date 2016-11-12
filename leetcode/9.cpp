class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int dev = 1;
        int high = 0;
        int low = 0;
        while(x/dev >=10){
            dev *= 10;
        }
        while(dev >= 10){
            high = x / dev;
            low = x % 10;
            if(high != low) {return false;}
            x = x % dev;
            x /= 10;
            dev /= 100;
        }
        return true;
    }
};
