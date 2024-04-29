#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> tmp;
vector<vector<bool>> visited;

int res = 0;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (map[ny][nx] == 0 && !visited[ny][nx]) {
					q.push({ nx, ny });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 1) {
					tmp[ny][nx]++;
				}
			}
		}
	}
}

bool melt() {
	bool check = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] > 1) {
				map[i][j] = 0;

				if (!check) {
					check = true;
				}
			}
		}
	}

	return check;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	tmp.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		bfs();

		if (!melt()) {
			break;
		}

		res++;
		tmp.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<bool>(M, false));
	}

	cout << res << '\n';

	return 0;
}