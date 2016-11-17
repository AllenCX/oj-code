#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        // if the string contains some illegal characters.
        if(digits.find("1")!=-1 || digits.find("*")!=-1 || 
            digits.find("#")!=-1 || digits.find("0")!=-1){
                return ret;
            }
        if(digits.size() == 0) return ret;
        string temps(digits.size(), ' ');
        string mp[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        DFS(mp, temps, ret, 0, digits);
        return ret;
    }
    
    void DFS(string mp[], string &temps, vector<string> &ret, int depth, string &digits){
        if(depth == digits.size()){
            ret.push_back(temps);
            return;
        }
        for(int i = 0; i < mp[digits[depth] - '0'].size(); ++i){
            temps[depth] = mp[digits[depth] - '0'][i];
            DFS(mp, temps, ret, depth+1, digits);
        }
    }
};
int main(int argc, char const *argv[])
{
	string ch= "abcdefghijklmnopqrstuvwxyz";
	char c = '#';
	cout << ch + c << endl;
	char cc = '2';
	cout << int(cc - '0') - 1 << endl;
	return 0;
}