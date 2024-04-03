#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	int start = 666;

	for (int i = 1; i < N; i++) {
		start++;
		while (true) {
			string str = to_string(start);
			if (str.find("666") != string::npos) {
				break;
			}
			start++;
		}
	}

	cout << start << '\n';

	return 0;
}