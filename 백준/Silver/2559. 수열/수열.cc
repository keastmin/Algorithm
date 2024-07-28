#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> sum;
int res = -987654321;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	sum.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	for (int i = N; i >= K; i--) {
		if (i - K >= 0) {
			sum[i] -= sum[i - K];
			res = max(sum[i], res);
		}
	}

	cout << res << '\n';

	return 0;
}