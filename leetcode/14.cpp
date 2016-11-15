#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        for(int i = 1; i <= strs[0].size(); ++i){
            string tmp = strs[0].substr(0, i);
            for(int j = 0; j < strs.size(); ++j){
                int found = strs[j].find(tmp);
                if(found != 0 || found == std::string::npos){
                    return ret;
                }
            }
            ret = tmp;
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
    std::vector<string> v(3);
    v[0] = "a";
    v[1] = "a";
    v[2] = "c";
    cout << s.longestCommonPrefix(v) << endl;
	return 0;
}