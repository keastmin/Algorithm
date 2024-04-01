#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		string str = to_string(n);
		int s = 0;
		int e = str.size() - 1;
		while (s < e) {
			char tmp = str[s];
			str[s++] = str[e];
			str[e--] = tmp;;
		}

		if (!str.compare(to_string(n))) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}