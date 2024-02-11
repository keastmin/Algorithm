#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool check(int x, int  y, int M, int N, vector<vector<bool>>& v) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	else if (v[y][x]) return false;
	return true;
}

int bfs(int N, int M, vector<vector<int>>& m) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 1 && !visited[i][j]) {
				count++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (check(nx, ny, M, N, visited)) {
							if (m[ny][nx] == 1) {
								q.push({ ny, nx });
								visited[ny][nx] = true;
							}
						}
					}
				}
			}
		}
	}

	return count;
}

int main() {
	int T, M, N, K;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		vector<vector<int>> map(N, vector<int>(M, 0));
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		cout << bfs(N, M, map) << '\n';
	}

	return 0;
}