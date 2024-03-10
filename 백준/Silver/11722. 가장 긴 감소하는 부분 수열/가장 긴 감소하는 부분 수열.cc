#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> arr(N + 1, 0);
	vector<int> dp(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	//cout << dp[N] << '\n';

	int res = 0;
	for (const auto d : dp) {
		res = max(res, d);
	}

	cout << res << '\n';

	return 0;
}