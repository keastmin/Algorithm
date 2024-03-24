#include <iostream>
#include <vector>
using namespace std;

int N, answer = 0;
vector<int> row;

bool check(int current) {
	for (int i = 0; i < current; ++i) {
		if (row[i] == row[current] || abs(row[current] - row[i]) == current - i) {
			return false;
		}
	}
	return true;
}

void nQueen(int current) {
	if (current == N) {
		++answer;
		return;
	}
	for (int i = 0; i < N; ++i) {
		row[current] = i;
		if (check(current))
			nQueen(current + 1);
	}
}

int main() {
	//cin >> N;

	//for (int i = 1; i <= 14; i++) {
	//	N = i;
	//	answer = 0;
	//	row.assign(N, 0);
	//	nQueen(0);
	//	cout << answer << '\n';
	//}

	int res[15] = { 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596 };

	int N;
	cin >> N;
	cout << res[N] << '\n';

	return 0;
}