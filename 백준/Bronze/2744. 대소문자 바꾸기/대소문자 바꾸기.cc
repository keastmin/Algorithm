#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	for (auto& s : str) {
		if (s <= 'Z' && s >= 'A') {
			s = tolower(s);
		}
		else if (s <= 'z' && s >= 'a') {
			s = toupper(s);
		}
	}

	cout << str << '\n';

	return 0;
}