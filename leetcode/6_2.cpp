#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
class Solution
{
public:
	string convert(string s, int numRows){
		if(numRows == 1) return s;
		if(numRows >= s.length()) return s;
		vector<string> ret(numRows);
		int step = 1;
		int row = 0;
		string ret_str = "";
		for(int i = 0; i < s.length(); ++i){
		    ret[row].append(string(1, s[i]));
		    if(row == 0){
		        step = 1;
		    }
		    if(row == numRows - 1){
		        step = -1;
		    }
		    row += step;
		}
		for(int i = 0; i < numRows; ++i){
		    ret_str.append(ret[i]);
		    cout << ret[i] << endl;
		}
		return ret_str;
	}
};
int main(){
	Solution s;
	string strr = "ABCD";
	cout << s.convert(strr, 3) << endl;
//	cout << qwe << endl;
}
