#include<iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	cin >> K;

	vector<pair<int, int>> dp(K + 1);
	dp[0] = { 1, 0 };

	for (int i = 1; i <= K; i++) {
		int A = dp[i - 1].first;
		int B = dp[i - 1].second;

		dp[i] = { B, B + A };

		//cout << i << ", " << dp[i].first << ", " << dp[i].second << '\n';
	}

	cout << dp[K].first << ' ' << dp[K].second << '\n';

	return 0;
}