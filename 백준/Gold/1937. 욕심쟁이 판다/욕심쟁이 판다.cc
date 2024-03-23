#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> dp;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int res = 0;

bool check(int x, int y) {
	if (x <= 0 || x > N || y <= 0 || y > N) return false;
	return true;
}

int dfs(int x, int y) {
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny)) {
			if (map[y][x] < map[ny][nx]) {
				dp[y][x] = max(dp[y][x], dfs(nx, ny) + 1);
			}
		}
	}

	return dp[y][x];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	map.resize(N + 1, vector<int>(N + 1));
	dp.resize(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res = max(res, dfs(j, i));
		}
	}

	cout << res << '\n';

	return 0;
}