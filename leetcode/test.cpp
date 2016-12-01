#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i = 1 << 2;
	int used = 3;
	cout << (i & used) << endl;
	return 0;
}