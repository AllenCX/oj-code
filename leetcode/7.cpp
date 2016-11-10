#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
    	int int_max = 2147483647;
        int int_min = -2147483648;
        int len = str.length();
        long long ret = 0;
        int flag = 1;
        if(len == 0) return 0;
        int j = 0;
        while(str[j] == ' '){
        	++j;
        }
        len = len - j;
        str = str.substr(j, len);
        if(str[0] == '+' || str[0] == '-') {
        	//++end;
        	if(str[0] == '+') flag = 1;
        	if(str[0] == '-') flag = -1;
        	str = str.substr(1, len - 1);
        	--len;
        }
        j = 0;
        while(48 <= int(str[j]) && int(str[j]) <= 57){
        	++j;
        }
        str = str.substr(0, j);
        len = j;
        for(int i = len - 1; i >= 0; --i){
            int char_num = int(str[i]);
            if(48 <= char_num && char_num <= 57){
            	ret = int(str[i] - 48) * pow(10, len - 1 - i);
            	if(ret * flag < int_min) {return int_min;}
  				if(ret * flag > int_max) {return int_max;}
            }else{
            	break;
            }
        }
  		return ret * flag;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	char c = '1';
	string str = "";
	long long int a = 21474836471;
	cout << s.myAtoi("    +1223a1") << endl;
	return 0;
}