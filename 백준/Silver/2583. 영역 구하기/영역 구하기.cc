#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<vector<bool>> v;

bool check(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	return true;
}

vector<int> bfs() {
	vector<int> res;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!v[i][j]) {
				int cnt = 1;
				queue<pair<int, int>> q;
				q.push({ j, i });
				v[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (check(nx, ny)) {
							if (!v[ny][nx]) {
								cnt++;
								v[ny][nx] = true;
								q.push({ nx, ny });
							}
						}
					}
				}

				res.push_back(cnt);
			}
		}
	}

	return res;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;
	v.resize(M, vector<bool>(N, false));

	for (int i = 0; i < K; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		for (int i = sy; i < ey; i++) {
			for (int j = sx; j < ex; j++) {
				v[i][j] = true;
			}
		}
	}

	vector<int> res = bfs();
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (const auto r : res) {
		cout << r << ' ';
	}

	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << v[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	return 0;
}