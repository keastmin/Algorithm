#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int s = 0;
	while (s < str.size()) {
		cout << str.substr(s, 10)<<'\n';
		s += 10;
	}

	return 0;
}