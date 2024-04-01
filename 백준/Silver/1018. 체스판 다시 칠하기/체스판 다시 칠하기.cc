#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
	string colorW = "WBWBWBWB";
	string colorB = "BWBWBWBW";
	
	vector<string> chess;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		chess.push_back(tmp);
	}

	int minC = INT_MAX;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			// 체스판 검증
			int wSC = 0;
			int bSC = 0;
			int wS = 0;
			int bS = 1;
			for (int k = 0; k < 8; k++) {
				for (int o = 0; o < 8; o++) {
					if (wS % 2 == 0) {
						if (chess[i + k][j + o] != colorW[o]) {
							wSC++;
						}
					}
					else {
						if (chess[i + k][j + o] != colorB[o]) {
							wSC++;
						}
					}

					if (bS % 2 == 0) {
						if (chess[i + k][j + o] != colorW[o]) {
							bSC++;
						}
					}
					else {
						if (chess[i + k][j + o] != colorB[o]) {
							bSC++;
						}
					}
				}
				wS++;
				bS++;
			}
			if (minC > wSC || minC > bSC) {
				minC = (wSC < bSC) ? wSC : bSC;
			}
		}
	}

	cout << minC << '\n';

	return 0;
}