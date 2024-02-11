#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool check(int x, int y, int n, int m, vector<vector<int>>& t) {
	if (x < 0 || x >= m || y < 0 || y >= n) return false;
	else if (t[y][x] == 1 || t[y][x] == -1) return false;
	return true;
}

int bfs(vector<vector<int>>& t, vector<vector<int>>& e, int n, int m) {
	queue<pair<int, int>> q;
	for (const auto i : e) q.push({ i[0], i[1] });
	int day = -1;
	int cS = q.size();

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cS--;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny, n, m, t)) {
				t[ny][nx] = 1;
				q.push({ nx, ny });
			}
		}

		if (cS == 0) {
			day++;
			cS = q.size();
		}
	}

	for (const auto i : t) {
		for (const auto c : i) {
			if (c == 0) return -1;
		}
	}

	return day;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	vector<vector<int>> tomato(N, vector<int>(M));
	vector<vector<int>> exist;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) exist.push_back({ j, i });
		}
	}

	cout << bfs(tomato, exist, N, M) << '\n';

	return 0;
}