#include <iostream>
#include <string>
using namespace std;

int main() {
	string n1;
	string n2;
	cin >> n1 >> n2;

	string n3 = "";

	for (int i = 0; i < 8; i++) {
		n3 += n1[i];
		n3 += n2[i];
	}

	string curr_str = n3;
	while (curr_str.size() > 2) {
		string tmp = "";

		for (int i = 1; i < curr_str.size(); i++) {
			int t = (curr_str[i - 1] - '0') + (curr_str[i] - '0');
			t = t % 10;
			tmp += to_string(t);
		}

		curr_str = tmp;
	}

	cout << curr_str << '\n';

	return 0;
}