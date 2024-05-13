#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> dp;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		arr.assign(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cin >> M;
		dp.assign(M + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= M; j++) {
				if (j - arr[i] >= 0) {
					dp[j] += dp[j - arr[i]];
				}
			}
		}

		cout << dp[M] << '\n';
	}

	return 0;
}