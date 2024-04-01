#include <iostream>
#include <vector>

using namespace std;

void dp(int x) {
	vector<vector<int>> fib(x + 1, {0, 0});
	fib[0][0] = 1;
	fib[0][1] = 0;
	if (x >= 1) {
		fib[1][0] = 0;
		fib[1][1] = 1;
	}
	if (x >= 2) {
		fib[2][0] = 1;
		fib[2][1] = 1;
	}

	for (int i = 3; i <= x; i++) {
		fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
		fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
	}

	cout << fib[x][0] << ' ' << fib[x][1] << '\n';
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		dp(x);
	}

	return 0;
}