#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int Sum(int dx, int mid, int dy, vector<vector<int>>& dp_mat) {
	return dp_mat[dx][mid] + dp_mat[mid + 1][dy];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;

		vector<int> arr(K + 1);
		vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));
		vector<int> sum(K + 1, 0);

		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < K; i++) {
			for (int dx = 1; dx + i <= K; dx++) {
				int dy = dx + i;
				dp[dx][dy] = numeric_limits<int>::max();

				for (int mid = dx; mid < dy; mid++) {
					dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + sum[dy] - sum[dx - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}

	return 0;
}