#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(const vector<vector<int>>& b, const int K) {
	vector<vector<int>> res(b.size(), vector<int>(K + 1));

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j < b.size(); j++) {
			if (b[j][0] > i) {
				res[j][i] = res[j - 1][i];
			}
			else {
				res[j][i] = max(res[j - 1][i - b[j][0]] + b[j][1], res[j - 1][i]);
			}
		}
	}

	return res[b.size() - 1][K];
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> backpack(N + 1, { 0, 0 });

	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		backpack[i] = { w, v };
	}

	int res = dp(backpack, K);
	cout << res << '\n';

	return 0;
}