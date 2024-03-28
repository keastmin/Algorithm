#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<vector<char>> map;

int sX, sY, eX, eY;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool check(int x, int y, vector<vector<bool>>& v) {
	if (x < 0 || x >= C || y < 0 || y >= R) return false;
	else if (v[y][x]) return false;
	else if (map[y][x] == 'X' || map[y][x] == '*') return false;
	return true;
}

void fillWater() {
	queue<pair<int, int>> q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];

					if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
						if (map[ny][nx] == '.') {
							q.push({ j, i });
						}
					}
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
				if ((nx != eX || ny != eY) && map[ny][nx] != 'X') {
					map[ny][nx] = '*';
				}
			}
		}
	}
}

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	q.push({ {sX, sY}, 0 });
	visited[sY][sX] = true;
	int prevDist = 0;
	fillWater();
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;

		if (prevDist != t) {
			fillWater();
			prevDist = t;
		}

		q.pop();

		if (x == eX && y == eY) {
			return t;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny, visited)) {
				q.push({ {nx, ny}, t + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	map.resize(R, vector<char>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S') {
				sX = j;
				sY = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'D') {
				eX = j;
				eY = i;
				map[i][j] = '.';
			}
		}
	}

	int res = bfs();

	if (res == -1) cout << "KAKTUS" << '\n';
	else cout << res << '\n';

	return 0;
}