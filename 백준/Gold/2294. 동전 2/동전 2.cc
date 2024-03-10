#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1, INT_MAX);
	vector<int> arr(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			int t = j - arr[i];

			if (dp[t] != INT_MAX) {
				dp[j] = min(dp[j], dp[t] + 1);
				//cout << t << ' '<<dp[j] << '\n';
			}
		}
		//cout << '\n';
	}

	//for (const auto d : dp) {
	//	cout << d << ' ';
	//}
	//cout << '\n';

	if (dp[K] == INT_MAX) cout << -1 << '\n';
	else cout << dp[K] << '\n';
	//cout << dp[K] << '\n';

	return 0;
}