#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0 ,0, -1, 1, 0, 0 };
int dz[6] = { 0 ,0, 0, 0, -1, 1 };

bool check(int x, int y, int z, int M, int N, int H) {
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H) return false;
	return true;
}

int bfs(vvvi& m, vvi& s, int M, int N, int H) {
	int day = -1;
	queue<vi> q;

	for (int i = 0; i < s.size(); i++) {
		int x = s[i][0];
		int y = s[i][1];
		int z = s[i][2];
		q.push({ x, y, z });
	}
	int dIdx = q.size();

	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int z = q.front()[2];
		q.pop();
		dIdx--;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (check(nx, ny, nz, M, N, H)) {
				if (m[nz][ny][nx] == 0) {
					q.push({ nx, ny, nz });
					m[nz][ny][nx] = 1;
				}
			}
		}

		if (dIdx == 0) {
			day++;
			dIdx = q.size();
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (m[i][j][k] == 0) {
					return -1;
				}
			}
		}
	}

	return day;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, H;
	cin >> M >> N >> H;

	vvvi map(H, vvi(N, vi(M)));
	vvi state;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];

				if (map[i][j][k] == 1) {
					state.push_back({ k, j, i });
				}
			}
		}
	}

	cout << bfs(map, state, M, N, H) << '\n';

	return 0;
}