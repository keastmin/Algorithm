#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool boardVisited[101];
int boardState[101];
int res = 0;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	boardVisited[1] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int turn = q.front().second;
		q.pop();

		if (curr == 100) {
			res = turn;
			return;
		}
		if (boardState[curr] != 0) {
			curr = boardState[curr];
		}
		

		for (int i = 1; i <= 6; i++) {
			int next = curr + i;

			if (next <= 100) {
				if (!boardVisited[next]) {
					q.push({ next, turn + 1 });
					boardVisited[next] = true;
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int x, y;
	for (int i = 0; i < N + M; i++) {
		cin >> x >> y;
		boardState[x] = y;
	}

	bfs();

	cout << res << '\n';

	return 0;
}