#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N;
vector<int> cost;
vector<int> people;
vector<int> dp;

int res = 9e8;

int main() {
	cin >> C >> N;
	cost.resize(N + 1);
	people.resize(N + 1);
	dp.resize(1000 * 100 + 1);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i] >> people[i];
	}

	for (int i = 1; i <= 1000 * 100; i++) {
		for (int j = 1; j <= N; j++) {
			if (i % cost[j] == 0) {
				dp[i] = max(dp[i], (i / cost[j]) * people[j]);
			}
			if (i - cost[j] >= 0) {
				dp[i] = max(dp[i], dp[i - cost[j]] + people[j]);
			}
		}

		if (C <= dp[i]) {
			res = i;
			break;
		}
	}

	cout << res << '\n';

	return 0;
}