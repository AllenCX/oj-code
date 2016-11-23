#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        if(num == 0) return ret;
        for(int i = 0; i <= num; ++i){
            if(i == 0) continue;
            //int n = log2(i);
            ret.push_back(int(1 + ret[i - pow(2, int(log2(i)))]));
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> v;
	v.push_back(0);
	int i = 3;
	//cout << pow(2, log2(1)) << endl;
	vector<int> v2 = s.countBits(16);
	for(int i = 0; i < v2.size(); ++i){
		cout << v2[i] << " ";	
	}
	
    return 0;
}