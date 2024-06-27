#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<int> dp;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1, 10000);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	dp[1] = 0;

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; i - j >= 1; ++j) {
			int pos = i - j;
			int jump = arr[pos];


			if (pos + jump >= i) {
				dp[i] = min(dp[i], dp[pos] + 1);
			}
		}
	}

	if (dp[N] == 10000) cout << -1 << '\n';
	else cout << dp[N] << '\n';

	return 0;
}