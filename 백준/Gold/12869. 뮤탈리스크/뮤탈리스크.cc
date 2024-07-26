#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

int N;
vector<int> SCV;
vvvi dp;

int Find3(int A, int B, int C) {
	if (A < 0) return Find3(0, B, C);
	if (B < 0) return Find3(A, 0, C);
	if (C < 0) return Find3(A, B, 0);

	if (A == 0 && B == 0 && C == 0)
		return 0;

	int& res = dp[A][B][C];

	if (res != -1) return res;

	res = 10e8;

	res = min(res, Find3(A - 9, B - 3, C - 1) + 1);
	res = min(res, Find3(A - 9, B - 1, C - 3) + 1);
	res = min(res, Find3(A - 3, B - 9, C - 1) + 1);
	res = min(res, Find3(A - 1, B - 9, C - 3) + 1);
	res = min(res, Find3(A - 3, B - 1, C - 9) + 1);
	res = min(res, Find3(A - 1, B - 3, C - 9) + 1);

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	SCV.resize(3, 0);
	dp.resize(61, vvi(61, vi(61, -1)));
	for (int i = 0; i < N; i++) {
		cin >> SCV[i];
	}

	cout << Find3(SCV[0], SCV[1], SCV[2]) << '\n';

	return 0;
}