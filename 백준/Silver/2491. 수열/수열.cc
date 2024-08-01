#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
vector<vector<int>> dp;
int res = 1;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N + 1, 0);
	dp.resize(N + 1, vector<int>(2, 0));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = 1;
		
		if (arr[i] >= arr[i - 1]) dp[i][0] = dp[i - 1][0] + 1;
		if (arr[i] <= arr[i - 1]) dp[i][1] = dp[i - 1][1] + 1;

		res = max({ res, dp[i][0], dp[i][1] });
	}

	cout << res << '\n';

	return 0;
}