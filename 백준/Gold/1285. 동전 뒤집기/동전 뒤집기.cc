#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int N;
vector<string> coins;

int tale(int r) {
	int ret = 0;

	for (int i = 0; i < N; i++) {
		int headCnt = 0;

		for (int j = 0; j < N; j++) {
			bool head = coins[j][i] == 'H';
			if ((r & (1 << j)) != 0) head = !head;
			if (head) headCnt++;

			// cout << "r = " << r << ", i = " << i << ", 1 << i = " << (1 << i) << ", r & (1 << i) = " << (r & (1 << i)) << '\n';
		}

		ret += min(headCnt, N - headCnt);
	}

	return ret;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	coins.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	int res = numeric_limits<int>::max();

	for (int i = 0; i < (1 << N); i++) {
		res = min(res, tale(i));
	}

	cout << res << '\n';

	return 0;
}