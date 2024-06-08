#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, L;
vector<pair<int, int>> snake;
vector<vector<int>> map;
vector<int> command;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int state = 0;
int snakeLength = 0;

int MoveSnake() {
	int currX = 0, currY = 0;
	int time = 0;
	bool check = false;
	while (true) {
		currX += dx[state];
		currY += dy[state];
		time++;

		if (currX < 0 || currY < 0 || currX >= N || currY >= N) check = true;
		else {
			for (int i = 0; i <= snakeLength; i++) {
				if (currX == snake[i].second && currY == snake[i].first) check = true;
			}
		}
		if (check) break;

		state += command[time];
		state = (state < 0) ? 3 : (state % 4);

		if (map[currY][currX] == 1) {
			map[currY][currX] = 0;
			snakeLength++;
			snake[snakeLength] = { currY, currX };
		}
		else {
			for (int i = 0; i <= snakeLength; i++) {
				if (i < snakeLength) {
					snake[i] = snake[i + 1];
				}
				else if (i == snakeLength) {
					snake[i] = { currY, currX };
				}
			}
		}
	}

	return time;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	map.resize(N, vector<int>(N, 0));
	snake.resize(10001, { 0, 0 });

	cin >> K;
	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		map[row - 1][col - 1] = 1;
	}

	cin >> L;
	command.resize(10001, 0);
	for (int i = 0; i < L; i++) {
		int turn;
		char com;
		cin >> turn >> com;
		command[turn] = (com == 'D') ? 1 : -1;
	}
	cout << MoveSnake() << '\n';
	return 0;
}