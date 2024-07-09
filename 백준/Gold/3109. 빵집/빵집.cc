#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> map;
vector<vector<bool>> visited;

int dx[3] = { 1, 1, 1 };
int dy[3] = { -1, 0, 1 };

int res = 0;

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
	return true;
}

// 기존 로직
/************************
void BackTrack(int x, int y) {
	if (isFind) return;

	visited[y][x] = true;

	if (x == C - 1) {
		isFind = true;
		res++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (CheckOverGrid(nx, ny)) {
			BackTrack(nx, ny);
		}
	}

	if (!isFind) {
		visited[y][x] = false;
	}
}
*************************/

// 기존의 방식은 일단 함수에 진입한 후 체크를 진행하기 때문에 함수 진입 오버헤드가 제법 큼
// 하지만 아래와 같은 방식은 함수에 진입하기 전 true 상태를 인지하여 조건문에서 걸러짐
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