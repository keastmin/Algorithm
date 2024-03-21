#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int N;
vector<pair<int, int>> arr;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> dp_mat;

int Sum(int dx, int mid, int dy) {
	return dp_mat[dx][mid].first * dp_mat[dx][mid].second * dp_mat[mid + 1][dy].second;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1, vector<int>(N + 1, 0));
	dp_mat.resize(N + 1, vector<pair<int, int>>(N + 1, { 0, 0 }));

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		dp_mat[i][i] = arr[i];
	}

	for (int i = 1; i < N; i++) {
		for (int dx = 1; dx + i <= N; dx++) {
			int dy = dx + i;
			dp[dx][dy] = numeric_limits<int>::max();
			for (int mid = dx; mid < dy; mid++) {
				dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + Sum(dx, mid, dy));
			}
			dp_mat[dx][dy].first = arr[dx].first;
			dp_mat[dx][dy].second = arr[dy].second;
		}
	}

	cout << dp[1][N] << '\n';

	return 0;
}