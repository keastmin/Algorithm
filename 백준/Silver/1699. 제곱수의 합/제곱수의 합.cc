#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dp(N + 1, 0);

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int t = i - j * j;
			dp[i] = min(dp[t] + 1, dp[i]);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}