#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<int> height;
unordered_map<int, bool> um;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N;
int low = 101;
int high = 0;
int res = 1;

bool check(int x, int y, vector<vector<bool>>& v, int s) {
	if (x < 0 || x >= N || y < 0 || y >= N) return false;
	else if (v[y][x]) return false;
	else if (map[y][x] <= s) return false;
	return true;
}

void bfs(int s) {
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > s && !visited[i][j]) {
				count++;
				queue<pair<int, int>> q;
				q.push({ j, i });
				visited[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (check(nx, ny, visited, s)) {
							q.push({ nx, ny });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
	}

	res = max(res, count);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	cin >> N;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			
			if (!um[map[i][j]]) {
				um[map[i][j]] = true;
				height.push_back(map[i][j]);
			}
		}
	}

	sort(height.begin(), height.end());

	for (int i = 0; i < height.size() - 1; i++) {
		bfs(height[i]);
	}

	cout << res << '\n';

	return 0;
}