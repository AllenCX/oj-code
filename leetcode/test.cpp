#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;
vector<int> f(string P){
	vector<int> pi(P.size(), -1);
	int m = P.size();
	int k = 0;
	for(int q = 1; q < m; ++q){
		while(k >= 0 && P[k + 1] != P[q]){
			k = pi[k];
		}
		if(P[k + 1] == P[q]){
			++k;
		}
		pi[q] = k;

	}
	return pi;
}
int main(){
	vector<int> v(5,1);
	for(auto i : v){
		cout << i ;
	}
}