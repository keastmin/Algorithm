#include<iostream>
#include <vector>
using namespace std;

int MaxInt(int a, int b) {
	if (a < b) return b;
	return a;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N + 1, 1);
	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i + 1] = MaxInt(dp[i + 1], dp[j + 1] + 1);
			}
		}
		res = MaxInt(dp[i + 1], res);
	}

	cout << res << '\n';

	return 0;
}