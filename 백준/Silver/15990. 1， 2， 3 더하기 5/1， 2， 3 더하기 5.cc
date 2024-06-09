#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000009

int T, N;
long long dp[100001][4];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD << '\n';
	}

	return 0;
}