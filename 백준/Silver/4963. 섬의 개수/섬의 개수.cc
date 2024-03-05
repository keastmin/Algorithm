#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dy[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };

bool check(int x, int y, int w, int h, vector<vector<int>>& m, vector<vector<bool>>& v) {
	if (x < 0 || x >= w || y < 0 || y >= h) return false;
	else if (v[y][x]) return false;
	else if (m[y][x] == 0) return false;
	return true;
}

int bfs(vector<vector<int>>& m, int w, int h) {
	int res = 0;
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visited[i][j] && m[i][j] == 1) {
				res++;
				queue<pair<int, int>> q;
				q.push({ j, i });
				visited[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 8; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (check(nx, ny, w, h, m, visited)) {
							visited[ny][nx] = true;
							q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
	

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	while (true) {
		int W, H;
		cin >> W >> H;
		if (W == 0 || H == 0) break;

		vector<vector<int>> map(H, vector<int>(W));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		cout << bfs(map, W, H) << '\n';
	}

	return 0;
}