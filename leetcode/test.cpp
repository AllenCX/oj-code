#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();
        int left, right;
        int len = 0;
        int startindex = 0;
        if(s.length() == 1) return s;
        for(int i = 0; i < str_len - 1; ++i){
            if(s[i]==s[i+1]){
                left = i;
                right = i + 1;
                search(s, left, right, len, startindex);
            }else{
                left = i;
                right = i;
                search(s, left, right, len, startindex);
            }
            if(len == 0){
                len = s.length();
            }
        }
        return s.substr(startindex, len);
    }
    void search(string s, int left, int right, int& len, int& startindex){
        int step = 1;
        while(0 <= (left-step) && (right+step) < s.length()){
            //if(left < 0 || right > s.length() - 1) break;
            if(s[left-step]!=s[right+step]){
                break;
            }
            step++;
        }
        int wid = right - left + 2 * step - 1;
        if(wid > len){
            len = wid;
            startindex = left - step + 1;
        }
    }
};
void test(int& a){
	a = 876;
}
int main(int argc, char const *argv[])
{
	Solution s;
	string str = "ccacc"; //step == 2 wil == 5 
	cout << s.longestPalindrome("aaaaabcba") << endl;
	cout << str.substr(1,3) << endl;
	cout << str.substr(1,4) << endl;
	cout << str.substr(0,5) << endl;



	return 0;
}