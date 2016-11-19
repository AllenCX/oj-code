#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp_ret;
        vector<vector<int>> ret;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        dfs(0, sum, ret, candidates, target, tmp_ret);
        return ret;
    }
    void dfs(int depth, int sum, vector<vector<int>> &ret, 
            vector<int> &candidates, int target, vector<int> &tmp_ret){
         if(sum > target) return;
         if(sum == target){
            ret.push_back(tmp_ret);
            return;
         }
         for(int i = depth; i < candidates.size(); ++i){
             sum += candidates[i];
             tmp_ret.push_back(candidates[i]);
             dfs(i+1, sum, ret, candidates, target, tmp_ret);
             sum -= candidates[i];
             tmp_ret.pop_back();
             while(i < candidates.size() && candidates[i] == candidates[i+1]) ++i;
         }
    }
};
int main(int argc, char const *argv[])
{
	bool flag[100][100];
    cout << flag[1][1] << endl;
}