#include <iostream>

using namespace std;

int main() {
	int a = 1;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		a = (a == 1) ? 0 : 1;
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			if ((i * 8 + j) % 2 == a && c == 'F') {
				count++;
			}
		}
	}

	cout << count << '\n';

	return 0;
}