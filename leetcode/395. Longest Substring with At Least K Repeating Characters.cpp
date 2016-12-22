class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size()) return 0;
        if(k == 0) return s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i){
            ++mp[s[i]];
        }
        int index = 0;
        while(index < s.size() && mp[s[index]] >= k) ++index;
        if(index == s.size()) return s.size();
        int left = longestSubstring(s.substr(0, index), k);
        int right = longestSubstring(s.substr(index + 1), k);
        return max(left, right);
    }
};