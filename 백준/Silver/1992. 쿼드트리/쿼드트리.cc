#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> arr;

char Check(int sx, int sy, int ex, int ey) {
	char s = arr[sy][sx];
	for (int i = sy; i < ey; i++) {
		for (int j = sx; j < ex; j++) {
			if (s != arr[i][j]) {
				return '2';
			}
		}
	}
	return s;
}

void FindRes(int sx, int sy, int ex, int ey) {
	char cR = Check(sx, sy, ex, ey);
	if (cR != '2') {
		cout << cR;
		return;
	}

	int midX = (sx + ex) / 2;
	int midY = (sy + ey) / 2;

	cout << "(";
	FindRes(sx, sy, midX, midY);
	FindRes(midX, sy, ex, midY);
	FindRes(sx, midY, midX, ey);
	FindRes(midX, midY, ex, ey);
	cout << ")";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	char cR = Check(0, 0, N, N);

	if (cR == '2') {
		FindRes(0, 0, N, N);
	}
	else {
		cout << cR << '\n';
	}


	return 0;
}