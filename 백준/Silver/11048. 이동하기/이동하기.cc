#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> dp;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	map.resize(N + 1, vector<int>(M + 1, 0));
	dp.resize(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];

			dp[i][j] = max(max(dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j]), dp[i - 1][j - 1] + map[i][j]);
			//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}

	cout << dp[N][M] << '\n';
	

	return 0;
}