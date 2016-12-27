#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
int main(){
	unordered_map<int, int> mp;
	mp[1] = 1;
	mp[2] = 4;
	mp[3] = 9;
	unordered_map<int, int>::iterator it = mp.begin();
	advance(it, 1);
	cout << it->first << endl;
	//cout << mp.size() << endl;
	int a[] = {1,2,3,4,5,6};
	vector<int> v(a, a+6);
	v.back() = 10;
	cout << v.back() << endl;
	return 0;
}