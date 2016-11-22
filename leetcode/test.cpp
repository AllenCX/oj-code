#include <string>
#include <iostream>
#include <set>

using namespace std;
int main(int argc, char const *argv[])
{
	set<string> my_set;
	set<string>::iterator tor;
	my_set.insert("1");
	my_set.insert("a");

    string s = "1234567";
    cout << s.substr(0 ,0 ) << endl;
    return 0;
}