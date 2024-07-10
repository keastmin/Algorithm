#include <iostream>
#include <vector>
using namespace std;

int res_max = -10e9;
int res_min = 10e9;
int N;
vector<int> arr;
vector<int> calc;

void Input() {
	cin >> N;
	arr.resize(N);
	calc.resize(4);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
}

void FindMinMax(int idx, int sum, int p, int s, int m, int d) {
	if (p + s + m + d == 0) {
		res_max = max(res_max, sum);
		res_min = min(res_min, sum);
		return;
	}

	int next = idx + 1;
	if (next < N) {
		if (p > 0) FindMinMax(next, sum + arr[next], p - 1, s, m, d);
		if (s > 0) FindMinMax(next, sum - arr[next], p, s - 1, m, d);
		if (m > 0) FindMinMax(next, sum * arr[next], p, s, m - 1, d);
		if (d > 0) FindMinMax(next, sum / arr[next], p, s, m, d - 1);
	}
}

void Solution() {
	FindMinMax(0, arr[0], calc[0], calc[1], calc[2], calc[3]);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solution();

	cout << res_max << '\n' << res_min << '\n';

	return 0;
}