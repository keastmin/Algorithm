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
	dp.resize(N + 1, 987654321);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}