#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        string str(n, '.');
        vector<string> tmp_ret(n, str);
        vector<int> x(n+1, 0);
        if(n == 0) return ret;
        dfs(1, ret, tmp_ret, x, n);
        return ret;
    }
    bool place(int t, vector<int> &x){
        for(int i = 1; i < t; ++i){
            if(abs(t - i) == abs(x[t] - x[i]) || x[i] == x[t]) return false;
        }
        return true;
    }
    void dfs(int depth, vector<vector<string>> &ret, vector<string> &tmp_ret,
        vector<int> &x, int n){
        if(depth > n){
            for(int i = 1; i <= n; ++i){
                tmp_ret[i-1][x[i]-1] = 'Q';
            }
            ret.push_back(tmp_ret);
            for(int i = 1; i <= n; ++i){
                tmp_ret[i-1][x[i]-1] = '.';
            }
            return;
        }
        for(int i = 1; i <= n; ++i){
            x[depth] = i;
            if(place(depth, x)) dfs(depth+1, ret, tmp_ret, x, n);
        }
    }
};
int main(int argc, char const *argv[])
{
	string str(4, '.');
	vector<string> v(4, str);
	cout << v[0] << endl;
	cout << str << endl;
	return 0;
}