#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
vector<vector<int>> map;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int res = 0;

bool check(int x, int y, vector<vector<bool>>& v) {
	if (x < 0 || x >= N || y < 0 || y >= N) return false;
	else if (v[y][x]) return false;
	return true;
}

bool bfs() {
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	bool move = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				queue<pair<int, int>> q;
				vector<pair<int, int>> setM;
				int cnt = 0;
				int sum = 0;
				q.push({ j, i });
				setM.push_back({ j, i });
				visited[i][j] = true;

				while (!q.empty()) {
					// cout << "작동" << '\n';
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					cnt++;
					sum += map[y][x];

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (check(nx, ny, visited)) {
							int diff = map[y][x] - map[ny][nx];
							diff = (diff < 0) ? (diff * (-1)) : diff;

							if (L <= diff && diff <= R) {
								q.push({ nx, ny });
								setM.push_back({ nx, ny });
								visited[ny][nx] = true;
							}
						}
					}
				}

				if (setM.size() > 1) move = true;

				sum /= cnt;
				for (const auto s : setM) {
					map[s.second][s.first] = sum;
				}
			}
		}
	}

	return move;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (bfs()) {
		//cout << "작동" << '\n';
		res++;
	}

	cout << res << '\n';

	return 0;
}