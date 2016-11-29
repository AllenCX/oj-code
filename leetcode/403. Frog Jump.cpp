
class Solution {
    unordered_map<int, unordered_map<int, bool>> m;
public:
    bool canCross(vector<int>& stones) {
        int res = 0;
        return helper(stones, 0, 0);
    }
    bool helper(vector<int> &stones, int index, int lastStep){
        if(m.count(index) && m[index].count(lastStep)){
            return m[index][lastStep];
        }
        for(int i = index + 1; i < stones.size(); ++i){
            if(stones[i] - stones[index] < lastStep - 1) continue;
            if(stones[i] - stones[index] > lastStep + 1){
                m[index][lastStep] = false;
                return false;
            }
            if(helper(stones, i, stones[i] - stones[index])) return true;
        }
        return index == stones.size() - 1;
    }
};
