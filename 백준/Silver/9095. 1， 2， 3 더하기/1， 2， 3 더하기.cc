#include <iostream>
#include <vector>

using namespace std;

int dp(int n) {
	vector<int> count(n + 1, 0);
	count[1] = 1;
	if (n >= 2) count[2] = 2;
	if (n >= 3) count[3] = 4;

	for (int i = 4; i <= n; i++) {
		count[i] = count[i - 3] + count[i - 2] + count[i - 1];
	}

	return count[n];
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp(n) << '\n';
	}

	return 0;
}