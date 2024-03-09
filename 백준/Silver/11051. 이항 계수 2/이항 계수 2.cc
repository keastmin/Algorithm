#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= min(i, K); j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[N][K] << '\n';

	return 0;
}