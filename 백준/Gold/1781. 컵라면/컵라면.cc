#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int deadMax = 0;
vector<pair<int, int>> arr;
priority_queue<int> pq;
long long res = 0;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		deadMax = max(deadMax, arr[i].first);
	}
	sort(arr.begin(), arr.end(), greater<>());

	int idx = 0;
	for (int i = deadMax; i > 0; i--) {
		while (idx < N && i == arr[idx].first) {
			pq.push(arr[idx].second);
			idx++;
		}

		if (!pq.empty()) {
			res += pq.top();
			//cout << res << '\n';
			pq.pop();
		}
	}

	cout << res << '\n';

	return 0;
}