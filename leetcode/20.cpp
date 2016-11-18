#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push_back(s[i]);
            }else{
                if(st.size() > 0){
                    char tmp = st.back();
                    if(mp[s[i]] != tmp) return false;
                    st.pop_back();    
                }else{
                    return false;   
                }
            }
        }
        if(st.size() == 0) return true;
        else return false;
    }
};