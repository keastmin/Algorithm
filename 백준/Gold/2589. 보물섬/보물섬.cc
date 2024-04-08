#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<string> map;
vector<pair<int, int>> newStart;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int res = 0;

bool check(int x, int y, vector<vector<bool>>& v) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	else if (v[y][x]) return false;
	else if (map[y][x] == 'W') return false;
	return true;
}

int bfs(int sX, int sY, vector<vector<bool>>& v) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sX, sY}, 0 });
	v[sY][sX] = true;

	int res = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		if (t > res) {
			res = t;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny, v)) {
				q.push({ {nx, ny}, t + 1 });
				v[ny][nx] = true;
			}
		}
	}

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	map.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				res = max(bfs(j, i, visited), res);
				visited.assign(N, vector<bool>(M, false));
			}
		}
	}

	cout << res << '\n';

	return 0;
}