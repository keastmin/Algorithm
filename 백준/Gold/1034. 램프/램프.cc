#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M, K;
vector<string> arr;
unordered_map<string, int> um;

int CountingZero(string str) {
	int cnt = 0;
	for (const auto& s : str) {
		if (s == '0') {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> K;

	for (const auto& ar : arr) {
		int cnt = CountingZero(ar);
		if (cnt > K || (cnt % 2 != K % 2))
			continue;
		if (um.find(ar) == um.end()) {
			um[ar] = 1;
		}
		else {
			um[ar]++;
		}
	}

	int res = 0;
	for (const auto& u : um) {
		res = max(res, u.second);
	}
	cout << res << '\n';

	return 0;
}