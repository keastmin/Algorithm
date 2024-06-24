#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;

int res = 0;

int StickCheck(int sx, int sy) {
	int sum1 = 0;
	int sum2 = 0;

	if (sx + 4 <= M) {
		for (int i = 0; i < 4; i++) {
			sum1 += map[sy][sx + i];
		}
	}

	if (sy + 4 <= N) {
		for (int i = 0; i < 4; i++) {
			sum2 += map[sy + i][sx];
		}
	}

	sum1 = max(sum1, sum2);
	return sum1;
}

int SquareCheck(int sx, int sy) {
	int sum = map[sy][sx] + map[sy + 1][sx] + map[sy][sx + 1] + map[sy + 1][sx + 1];
	return sum;
}

int LSCheck(int sx, int sy) {
	int dx[2] = { -1, 1 };
	int dy[2] = { -1, 1 };
	int r = 0;

	for (int i = 0; i < 2; i++) {
		int cx = sx + (2 * dx[i]);
		if (cx >= 0 && cx < M) {
			for (int j = 0; j < 2; j++) {
				int cy = sy + dy[j];
				if (cy >= 0 && cy < N) {
					int sum1 = map[sy][sx] + map[sy][sx + dx[i]] + map[sy][cx] + map[cy][cx];
					int sum2 = map[sy][sx] + map[sy][sx + dx[i]] + map[cy][sx + dx[i]] + map[cy][cx];
					r = max(r, max(sum1, sum2));
				}
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		int cy = sy + (2 * dy[i]);
		if (cy >= 0 && cy < N) {
			for (int j = 0; j < 2; j++) {
				int cx = sx + dx[j];
				if (cx >= 0 && cx < M) {
					int sum1 = map[sy][sx] + map[sy + dy[i]][sx] + map[cy][sx] + map[cy][cx];
					int sum2 = map[sy][sx] + map[sy + dy[i]][sx] + map[sy + dy[i]][cx] + map[cy][cx];
					r = max(r, max(sum1, sum2));
				}
			}
		}
	}

	return r;
}

int TCheck(int sx, int sy) {
	int dx[4] = { -1, 1 };
	int dy[4] = { -1, 1 };
	int r = 0;

	for (int i = 0; i < 2; i++) {
		int i1 = sx + dx[i]; int i2 = sy + dy[0]; int i3 = sy + dy[1];
		if (i1 >= 0 && i1 < M && i2 >= 0 && i2 < N && i3 >= 0 && i3 < N) {
			int sum = map[sy][sx] + map[sy][i1] + map[i2][sx] + map[i3][sx];
			r = max(r, sum);
		}
	}

	for (int i = 0; i < 2; i++) {
		int i1 = sy + dy[i]; int i2 = sx + dx[0]; int i3 = sx + dx[1];
		if (i1 >= 0 && i1 < N && i2 >= 0 && i2 < M && i3 >= 0 && i3 < M) {
			int sum = map[sy][sx] + map[i1][sx] + map[sy][i2] + map[sy][i3];
			r = max(r, sum);
		}
	}

	return r;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(i + 4 <= N || j + 4 <= M)
				res = max(res, StickCheck(j, i));
		}
	}

	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 2; j++) {
			res = max(res, SquareCheck(j, i));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res = max(res, LSCheck(j, i));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res = max(res, TCheck(j, i));
		}
	}
	
	cout << res << '\n';

	return 0;
}