#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> dp[1001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		int dSize = 0;
		int jSave = 0;

		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dSize < dp[j].size() + 1) {
					dSize = dp[j].size() + 1;
					jSave = j;
				}
			}
		}

		dp[i] = dp[jSave];
		dp[i].push_back(arr[i]);
	}

	int maxSize = 0;
	int maxIdx = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i].size() > maxSize) {
			maxSize = dp[i].size();
			maxIdx = i;
		}
	}

	cout << dp[maxIdx].size() << '\n';
	for (const auto d : dp[maxIdx]) {
		cout << d << ' ';
	}

	return 0;
}