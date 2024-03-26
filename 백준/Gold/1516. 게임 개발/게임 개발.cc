#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

vector<pair<int, vector<int>>> arr;
vector<int> inDeg;
vector<int> dp;

void topol() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
			dp[i] = arr[i].first;
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (const int a : arr[curr].second) {
			inDeg[a]--;

			dp[a] = max(dp[a], dp[curr] + arr[a].first);
			if (inDeg[a] == 0) q.push(a);
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	arr.resize(N + 1);
	inDeg.resize(N + 1, 0);
	dp.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		int a;
		while (true) {
			cin >> a;
			if (a == -1) break;
			arr[a].second.push_back(i);
			inDeg[i]++;
		}
	}

	topol();

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << '\n';
	}

	return 0;
}