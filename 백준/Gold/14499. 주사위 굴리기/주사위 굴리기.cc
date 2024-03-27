#include <iostream>
#include <vector>
using namespace std;

struct Dice {
	int front, back, top, bottom, left, right;
	Dice() {
		front = back = top = bottom = left = right = 0;
	}
};

int N, M, sX, sY, K;
vector<vector<int>> map;
vector<int> command;

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

Dice dice;

void DiceChange(int c) {
	int tmp;
	if (c == 1) {
		tmp = dice.right;
		dice.right = dice.top;
		dice.top = dice.left;
		dice.left = dice.bottom;
		dice.bottom = tmp;
	}
	else if (c == 2) {
		tmp = dice.left;
		dice.left = dice.top;
		dice.top = dice.right;
		dice.right = dice.bottom;
		dice.bottom = tmp;
	}
	else if (c == 3) {
		tmp = dice.back;
		dice.back = dice.top;
		dice.top = dice.front;
		dice.front = dice.bottom;
		dice.bottom = tmp;
	}
	else if (c == 4) {
		tmp = dice.front;
		dice.front = dice.top;
		dice.top = dice.back;
		dice.back = dice.bottom;
		dice.bottom = tmp;
	}
}

bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> sY >> sX >> K;
	map.resize(N, vector<int>(M));
	command.resize(K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
		cin >> command[i];

	for (const auto c : command) {
		sX += dx[c];
		sY += dy[c];
		if (check(sX, sY)) {
			DiceChange(c);

			if (map[sY][sX] == 0) {
				map[sY][sX] = dice.bottom;
			}
			else {
				dice.bottom = map[sY][sX];
				map[sY][sX] = 0;
			}

			cout << dice.top << '\n';
		}
		else {
			sX -= dx[c];
			sY -= dy[c];
		}
	}

	return 0;
}