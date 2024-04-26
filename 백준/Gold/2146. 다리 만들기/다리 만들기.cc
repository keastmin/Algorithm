#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int res = numeric_limits<int>::max();

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void divIsland(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		map[y][x] = cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[ny][nx] != 0 && !visited[ny][nx]) {
					q.push({ nx, ny });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int fourDirectionCheck(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[ny][nx] != 0) {
				return map[ny][nx];
			}
		}
	}

	return -1;
}

void minimumBridge(int sX, int sY, int num) {
	queue<tuple<int, int, int>> q;
	q.push({ sX, sY, 1 });
	visited[sY][sX] = true;

	while (!q.empty()) {
		int x, y, d;
		tie(x, y, d) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[ny][nx] != num && map[ny][nx] != 0) {
					res = min(res, d);
					return;
				}

				if (!visited[ny][nx] && map[ny][nx] == 0) {
					q.push({ nx, ny, d + 1 });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	map.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int islandCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				islandCnt++;

				divIsland(j, i, islandCnt);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				int islandNum = fourDirectionCheck(j, i);

				if (islandNum > 0) {
					minimumBridge(j, i, islandNum);

					visited.assign(N, vector<bool>(N, false));
				}
			}
		}
	}

	cout << res << '\n';

	return 0;
}