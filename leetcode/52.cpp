#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int ret;
        if(n == 0) return 0;
        vector<int> pos(n+1, 0);
        int sum = 0;
        dfs(1, ret, pos, sum, n);
        return ret;
    }
    bool place(int n, vector<int> &pos){
        for(int i = 1; i < n; ++i){
            if(abs(pos[i] - pos[n]) == 0||pos[i] == pos[n]) return false;
        }
        return true;
    }
    void dfs(int depth, int &ret, vector<int> &pos, int &sum, int n){
        if(depth > n){
            ++sum;
            return;
        }
        for(int i = 1; i <= n; ++i){
            pos[depth] = i;
            if(place(n, pos)) dfs(depth+1, ret, pos, sum, n);
        }
    }
};
void f(int &a){
	a++;
	return;
}
int main(int argc, char const *argv[])
{
	int a = 0;
	f(a);
	cout << a << endl;
	return 0;
}