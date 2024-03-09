#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> map;
vector<bool> visited;
int R, C;
int res = 1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int c) {
	if (c > res) res = c;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
			int t = map[ny][nx] - 'A';
			if (!visited[t]) {
				visited[t] = true;
				dfs(nx, ny, c + 1);
				visited[t] = false;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	map.resize(R);
	visited.resize(26, false);
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	int t = map[0][0] - 'A';
	visited[t] = true;
	dfs(0, 0, 1);

	cout << res << '\n';

	return 0;
}