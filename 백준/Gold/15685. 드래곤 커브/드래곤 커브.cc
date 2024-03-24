#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> map(101, vector<bool>(101, false));

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<int> curve;
		curve.push_back(d);
		int lastPos[2] = {x + dx[d], y + dy[d]};

		map[y][x] = true;
		map[y + dy[d]][x + dx[d]] = true;

		for (int j = 1; j <= g; j++) {
			int k = curve.size() - 1;

			for (k; k >= 0; k--) {
				d = (curve[k] + 1) % 4;
				lastPos[0] += dx[d];
				lastPos[1] += dy[d];

				map[lastPos[1]][lastPos[0]] = true;
				curve.push_back(d);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				res++;
			}
		}
	}

	cout << res << '\n';

	return 0;
}