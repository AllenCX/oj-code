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
		int str_len = s.length();
		double n_block = double(str_len) / double(2 * (numRows - 1));
		string ret = "";
		string *tmp;
		int rest_str = 0;

		//cout <<" check 1" <<endl;
 		//cout << n_block << endl;
		if(int(n_block) - n_block != 0) {

			n_block = ceil(n_block);
			rest_str = str_len % int(n_block);
		}
		//cout << str_len << endl;
		//cout << rest_str << endl;
		vector<string> sub_str(numRows);
		char char_1;
		char char_2;
		for(int i = 0; i < numRows; ++i){
			//cout << "now i = " << i << endl;
			if(i != (numRows - 1) && i != 0){
				for(int j = 0; j < n_block; ++j){
					char_1 = s[j*(numRows - 1)*2 + i];
					char_2 = s[j*(numRows - 1)*2 + (numRows - 1)*2 - i];
					if(j*(numRows - 1)*2 + i < str_len) {
						sub_str[i] += string(1, char_1);
					}
					if(j*(numRows - 1)*2 + (numRows - 1)*2 - i < str_len){ 
						sub_str[i] += string(1, char_2);
					}
					//cout << j*(numRows - 1)*2 + (numRows - 1)*2 - i <<endl;
					//cout << str_len << endl;
					//cout<< sub_str[i] << endl;
				}
			}
			if(i == 0){
				for(int j = 0; j < n_block; ++j){
					char_1 = s[j*(numRows - 1)*2 + i];
					if(j*(numRows - 1)*2 + i < str_len) {
						sub_str[i] += string(1, char_1);
					}	
					//cout<< sub_str[i] << endl;
				}
			}
			if(i == (numRows - 1)){
				for(int j = 0; j < n_block; ++j){
					char_1 = s[j*(numRows - 1)*2 + i];
					if(j*(numRows - 1)*2 + i < str_len) {
						sub_str[i] += string(1, char_1);
					}					
					//cout<< sub_str[i] << endl;
				}
			}
		}
		//cout <<" check 2" <<endl;
		for(int i = 0; i < numRows; ++i){
			ret.append(sub_str[i]) ;
		}
		//cout <<" check 3" <<endl;
		return ret;
	}
};

int main(){
	Solution s;
	vector<int> v1(5);
	vector<int> v2(1);
	string *str = new string("ad");
	string s1 = "abc";
	string s2 = "";

	vector<string> v_str(2);
	v_str[0] = "bbbas2";
	v_str[1] = "aasd1";
	string ssss = "";
	for(int i = 0; i < 2; ++i){
		ssss += v_str[i];
	}
	char qwe;
	string strr = "pdhoozufbkgswhmwruzpdfgysycpvmwlrfzfevkhitagaoctiejnlrodpqskeqxvwzccwpkekmkmapgltryeimjzeblirjfpkksgzeljqxvsmddhueleswdxxrhrapgmzasaeflwdippmuxiykpthssgjzzlqgxrisrnxelanaszxrjxdyqmtiteksqaapsljlahqljdodeluniamzmhhhltcduevopebpnrdzwrcaczqmzelnlvvwozakdvyvbakptpoqgqskrixqmkezfbwwaygfthauhnlcczsjsnvjvsakdgjkjhglfpqawrxfeijiietcrplmhnymvixepfpvwivuzsbfdlnnpjpgyaufotslbrqsyhpvpnpohrvkclxtumzsptzfmtqpkgkjqzefmvwumteqeejaskuheumsndkalulbtrhimfczyirdmdffnaotwbmlgyltsyvnpevclxdjiuowxudnwsgsvufdsrwkrtahzvjkvoudikbiefvaxduuyaxqtvdkpdtqacbvqxabhclohiqgllcjnzciwfulkockqfgjcimlkxztfqbsddeqeiybnsozgsjzzrkdawpmtqiaglujrabxibyxwpwejgfjxpmzlboguwiahfmafpyorylpnitxqzipoupcyfisbtukyildyjtrhhgxpzwhyewpanrasbstupguxtavevmncsktui";
	cout << s.convert(strr, 503) << endl;
//	cout << qwe << endl;
}
