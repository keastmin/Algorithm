#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		// if (!pq.empty()) cout << pq.top() << '\n';

		pq.push(arr[i].second);
		if (pq.top() <= arr[i].first) pq.pop();
	}

	cout << pq.size() << '\n';

	return 0;
}