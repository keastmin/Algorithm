#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> map;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int res = 0;

pair<int, int> FindNearIdx(int x, int y, int dir) {
	int nearX = x;
	int nearY = y;

	while (true) {
		nearX += dx[dir];
		nearY += dy[dir];

		if (nearX < 0 || nearX >= N || nearY < 0 || nearY >= N) {
			nearX -= dx[dir];
			nearY -= dy[dir];
			break;
		}
		else if (map[nearY][nearX] > 0) {
			nearX -= dx[dir];
			nearY -= dy[dir];
			break;
		}
	}

	return { nearX, nearY };
}

void MoveRight() {
	for (int i = 0; i < N; i++) {
		int prev = 0;

		for (int j = N - 1; j >= 0; j--) {
			if (map[i][j] > 0) {
				int curr = map[i][j];
				pair<int, int> nearPos = FindNearIdx(j, i, 0);
				int near = nearPos.first;
				map[i][j] = 0;

				if (prev != curr) {
					prev = curr;
					map[i][near] = curr;
				}
				else if(prev == curr) {
					prev = 0;
					map[i][near + 1] = curr * 2;
				}
			}
		}
	}
}

void MoveLeft() {
	for (int i = 0; i < N; i++) {
		int prev = 0;

		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0) {
				int curr = map[i][j];
				pair<int, int> nearPos = FindNearIdx(j, i, 2);
				int near = nearPos.first;
				map[i][j] = 0;

				if (prev != curr) {
					prev = curr;
					map[i][near] = curr;
				}
				else if (prev == curr) {
					prev = 0;
					map[i][near - 1] = curr * 2;
				}
			}
		}
	}
}

void MoveUp() {
	for (int j = 0; j < N; j++) {
		int prev = 0;

		for (int i = 0; i < N; i++) {
			if (map[i][j] > 0) {
				int curr = map[i][j];
				pair<int, int> nearPos = FindNearIdx(j, i, 3);
				int near = nearPos.second;
				map[i][j] = 0;

				if (prev != curr) {
					prev = curr;
					map[near][j] = curr;
				}
				else if (prev == curr) {
					prev = 0;
					map[near - 1][j] = curr * 2;
				}
			}
		}
	}
}

void MoveDown() {
	for (int j = 0; j < N; j++) {
		int prev = 0;

		for (int i = N - 1; i >= 0; i--) {
			if (map[i][j] > 0) {
				int curr = map[i][j];
				pair<int, int> nearPos = FindNearIdx(j, i, 1);
				int near = nearPos.second;
				map[i][j] = 0;

				if (prev != curr) {
					prev = curr;
					map[near][j] = curr;
				}
				else if (prev == curr) {
					prev = 0;
					map[near + 1][j] = curr * 2;
				}
			}
		}
	}
}

int FindMaxNum() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num = max(num, map[i][j]);
		}
	}
	return num;
}

void Move(int cnt) {
	if (cnt == 5) {
		res = max(res, FindMaxNum());
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> tmp = map;

		if (i == 0) MoveRight();
		else if (i == 1) MoveDown();
		else if (i == 2) MoveLeft();
		else if (i == 3) MoveUp();

		Move(cnt + 1);

		map = tmp;
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> tmp = map;

		if (i == 0) MoveRight();
		else if (i == 1) MoveDown();
		else if (i == 2) MoveLeft();
		else if (i == 3) MoveUp();

		Move(1);

		map = tmp;
	}

	cout << res << '\n';

	return 0;
}