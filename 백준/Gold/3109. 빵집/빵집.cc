#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> map;
vector<vector<bool>> visited;

int dx[3] = { 1, 1, 1 };
int dy[3] = { -1, 0, 1 };

int res = 0;
bool isFind = false;

void Input() {
	cin >> R >> C;
	map.resize(R, vector<char>(C));
	visited.resize(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
}

bool CheckOverGrid(int x, int y) {
	if (y < 0 || y >= R) return false;
	else if (map[y][x] == 'x') return false;
	//else if (visited[y][x]) return false;
	return true;
}

bool BackTrack(int x, int y) {
	if (x == C - 1) {
		res++;
		return true;
	}

	map[y][x] = 'x';


	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (CheckOverGrid(nx, ny)) {
			if (BackTrack(nx, ny)) return true;
		}
	}

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	
	for (int i = 0; i < R; i++) {
		BackTrack(0, i);
	}

	cout << res << '\n';

	return 0;
}