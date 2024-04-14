#include <iostream>
using namespace std;

int main() {
	int N = 0;
	int res = 0;

	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;

		N -= a;
		N += b;

		if (N > res) res = N;
	}

	cout << res << '\n';

	return 0;
}