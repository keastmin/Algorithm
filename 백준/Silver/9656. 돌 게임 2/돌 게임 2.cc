#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dp(N + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] == 1) ? 0 : 1;
	}

	if (dp[N]) cout << "CY" << '\n';
	else cout << "SK" << '\n';

	return 0;
}