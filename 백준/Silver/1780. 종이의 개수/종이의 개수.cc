#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> paper;
int res[3];

void Input() {
	cin >> N;
	paper.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
}

int CheckPaperColor(int sX, int sY, int l) {
	int s = paper[sY][sX];
	for (int i = sY; i < sY + l; i++) {
		for (int j = sX; j < sX + l; j++) {
			if (s != paper[i][j]) {
				return -1;
			}
		}
	}
	if (s == -1) return 0;
	if (s == 0) return 1;
	return 2;
}

void CountPaper(int sX, int sY, int l) {
	int c = CheckPaperColor(sX, sY, l);
	if (c > -1) {
		res[c]++;
		return;
	}

	int nl = l / 3;

	for (int i = sY; i < sY + l; i += nl) {
		for (int j = sX; j < sX + l; j += nl) {
			CountPaper(j, i, nl);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	CountPaper(0, 0, N);	
	for (int i = 0; i < 3; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}