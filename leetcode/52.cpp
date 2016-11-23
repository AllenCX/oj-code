#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        if(n == 0) return 0;
        vector<int> pos(n+1, 0);
        int sum = 0;
        dfs(1, pos, sum, n);
        return sum;
    }
    bool place(int t, vector<int> &pos){
        for(int i = 1; i < t; ++i){
            if(abs(pos[i] - pos[t]) == abs(i - t)||pos[i] == pos[t]) return false;
        }
        return true;
    }
    void dfs(int depth, vector<int> &pos, int &sum, int n){
        if(depth > n){
            sum += 1;
            return;
        }
        for(int i = 1; i <= n; ++i){
            pos[depth] = i;
            if(place(depth, pos)) dfs(depth+1, pos, sum, n);
        }
    }
};
int main(int argc, char const *argv[])
{
	int a = 0;
	f(a);
	cout << a << endl;
	return 0;
}