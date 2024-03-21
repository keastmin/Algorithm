#include <iostream>
using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	
	dp[N][N] = 1;
	for (int i = 1; i < N; i++) {
		dp[i][i] = 1;
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}

	for (int len = 3; len <= N; len++) {
		for (int s = 1; s + len - 1 <= N; s++) {
			int e = s + len - 1;
			if (arr[s] == arr[e] && dp[s + 1][e - 1] == 1) dp[s][e] = 1;
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}