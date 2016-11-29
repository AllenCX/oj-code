#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool ret = false;
        int numLen = nums.size();
        //sort(nums.begin(), nums.end());

        nums.push_back(0);
        cout << nums.size() << endl;
        if(numLen == 0) return false;
        int c = 0;
        for(int i = numLen; i > 0; --i){
            nums[i] = nums[i-1]; //make the first element at nums[1] instead of nums[0]
            cout << nums[i] << " ";
            c += nums[i];
        } 
        cout << endl;
        if(c % 2 == 1) return false; // if the summation of nums is odd, return false
        // backpack problem
        c /= 2; // capacity
        cout << "c = " << c << endl; 
        vector< vector<int> > m(numLen + 1, vector<int>(c + 1, 0)); //index start from 1 not 0
        //cout << "check 0" << endl; 
        for(int j = nums[numLen]; j <= c; ++j){
            m[numLen][j] = nums[numLen];
        } 
        //cout << "check 1" << endl; 
        for(int i = numLen - 1; i > 0; --i){
            int jMax = min(nums[i] - 1, c);
            for(int j = 0; j <= jMax; ++j) m[i][j] = m[i + 1][j];
            for(int j = nums[i]; j <= c; ++j)
                m[i][j] = max(m[i + 1][j], m[i + 1][j - nums[i]] + nums[i]);
        }
        m[1][c] = m[2][c];
        if(nums[1] <= c) m[1][c] = max(m[2][c], m[2][c - nums[1]] + nums[1]);

        for(int i = 1; i < m.size(); ++i){
            for(int j = 1; j < m[0].size(); ++j){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        if(m[1][c] == c) return true;
        else return false;
    }   
};
int main(){
	Solution s;
	int n[] = {5,3,2,2};
	vector<int> v(n, n+4);
	cout << s.canPartition(v) << endl;
	return 0;
}