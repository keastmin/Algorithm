#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool check(int x, int y, int l, vector<vector<bool>>& v) {
	if (x < 0 || x >= l || y < 0 || y >= l) return false;
	else if (v[y][x]) return false;
	return true;
}

int bfs(int sx, int sy, int ex, int ey, int l) {
	int cnt = 0;
	int res = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(l, vector<bool>(l, false));

	q.push({ sx, sy });
	visited[sy][sx] = true;
	cnt = q.size();

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt--;

		if (x == ex && y == ey) return res;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny, l, visited)) {
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}

		if (cnt == 0) {
			res++;
			cnt = q.size();
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int l, sx, sy, ex, ey;
		cin >> l >> sx >> sy >> ex >> ey;

		cout << bfs(sx, sy, ex, ey, l) << '\n';
	}

	return 0;
}