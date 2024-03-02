#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> arr(N + 1, { 0, 0});
	vector<int> dp(N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	int res = 0;
	for (int i = 0; i <= N; i++) {
		int next = arr[i].first;

		dp[i] = max(res, dp[i]);
		if (i + next <= N) {
			dp[i + next] = max(dp[i + next], dp[i] + arr[i].second);
		}
		res = max(res, dp[i]);
	}

	//for (int i = 1; i <= N; i++) {
	//	cout << dp[i] << '\n';
	//}

	cout << res << '\n';

	return 0;
}