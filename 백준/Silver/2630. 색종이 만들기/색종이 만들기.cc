#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> arr;
int bres, wres;

void Input() {
	cin >> N;
	arr.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

int CheckAllColor(int sX, int sY, int eX, int eY) {
	int size = (eX - sX) * (eY - sY);
	int wC = 0;
	int bC = 0;

	for (int i = sY; i < eY; i++) {
		for (int j = sX; j < eX; j++) {
			if (arr[i][j] == 1) bC++;
			else wC++;
		}
	}

	if (bC == size) {
		return 1;
	}
	if (wC == size) {
		return 0;
	}
	return -1;
}

void CutPaper(int sX, int sY, int eX, int eY) {
	int res = CheckAllColor(sX, sY, eX, eY);

	if (res == 1) {
		bres++;
		return;
	}
	if (res == 0) {
		wres++;
		return;
	}

	if (sX < eX && sY < eY) {
		int midX = (sX + eX) / 2;
		int midY = (sY + eY) / 2;

		CutPaper(sX, sY, midX, midY);
		CutPaper(midX, sY, eX, midY);
		CutPaper(sX, midY, midX, eY);
		CutPaper(midX, midY, eX, eY);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x = 0, xx = 8;

	Input();
	CutPaper(0, 0, N, N);
	cout << wres << '\n' << bres << '\n';

	return 0;
}