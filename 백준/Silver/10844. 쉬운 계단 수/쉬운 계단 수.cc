#include<iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int res = 0;
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10, 0));

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) {
		res += dp[N][i];
		res = res % 1000000000;
	}

	cout << res << '\n';

	return 0;
}