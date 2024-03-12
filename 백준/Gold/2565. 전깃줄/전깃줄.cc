#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
vector<int> dp;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1);
	
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	sort(arr.begin() + 1, arr.end());

	int res = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if(arr[i].second > arr[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(dp[i], res);
	}

	cout << N - res << '\n';

	return 0;
}