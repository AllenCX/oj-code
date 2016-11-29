class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        int i = s.size() - 1;
        int j = t.size() - 1;
        while(i >= 0){
            if(s[i] == t[j]){
                --i;
                --j;
            }else{
                --j;
            }
            if(i == -1) return true;
            if(i >= 0 && j < 0) return false;
        }
        return false;
    }
};