#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct State {
	int rx, ry, bx, by, move;
};

int N, M;
vector<string> map;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void moveBall(int& x, int& y, int& moved, int i) {
	moved = 0;
	while (map[y + dy[i]][x + dx[i]] != '#' && map[y][x] != 'O') {
		x += dx[i];
		y += dy[i];
		moved++;
	}
}

int bfs(State start) {
	queue<State> q;
	bool visited[11][11][11][11] = { false };
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = true;

	while (!q.empty()) {
		State curr = q.front();
		q.pop();

		if (curr.move >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = curr.rx, nry = curr.ry, nbx = curr.bx, nby = curr.by;
			int rMoved, bMoved;
			moveBall(nrx, nry, rMoved, i);
			moveBall(nbx, nby, bMoved, i);

			if (map[nby][nbx] == 'O') continue;
			if (map[nry][nrx] == 'O') return curr.move + 1;

			if (nrx == nbx && nry == nby) {
				if (rMoved > bMoved) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = true;
				q.push({ nrx, nry, nbx, nby, curr.move + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	State start;
	map.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				start.rx = j;
				start.ry = i;
			}
			if (map[i][j] == 'B') {
				start.bx = j;
				start.by = i;
			}
		}
	}
	start.move = 0;
	cout << bfs(start) << '\n';

	return 0;
}