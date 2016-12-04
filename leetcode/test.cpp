#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<int> v;
	v.push_back(1);
	vector<int> v2;
	v2.push_back(2);
	v.push_back(v2);
	cout << v.size() << endl;
}