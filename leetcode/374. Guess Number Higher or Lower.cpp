// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int mid = 1 + (n - 1) / 2;
        int guess_res = guess(mid);
        while(guess_res != 0){
            if(guess_res == -1){
                r = mid;
            }else if(guess_res == 1){
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
            guess_res = guess(mid);
        }
        return mid;
    }
};