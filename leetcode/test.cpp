#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main(){
	map<int, int> mp;
	mp[1] = 0;
	mp[2] = 3;
	mp[3] = 4;
	cout << (mp.find(5) == mp.end()) << endl;
	cout << mp.count(1) << endl;
	return 0;
}