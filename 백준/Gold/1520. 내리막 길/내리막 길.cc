#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> dp;
int M, N;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

bool check(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M) return false;
	return true;
}

int dfs(int x, int y) {
	if (x == N && y == M) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check(nx, ny)) {
			if (map[ny][nx] < map[y][x]) {
				dp[y][x] += dfs(nx, ny);
			}
		}
	}

	return dp[y][x];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	map.resize(M + 1, vector<int>(N + 1, 0));
	dp.resize(M + 1, vector<int>(N + 1, -1));
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(1, 1) << '\n';

	//cout << '\n';
	//for (const auto dpp : dp) {
	//	for (const auto d : dpp) {
	//		cout << d << ' ';
	//	}
	//	cout << '\n';
	//}

	return 0;
}