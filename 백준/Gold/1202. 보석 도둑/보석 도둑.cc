#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> jewels(N);
	for (int i = 0; i < N; i++) {
		cin >> jewels[i].second >> jewels[i].first;
	}

	multiset<int> bags;
	for (int i = 0; i < K; i++) {
		int C;
		cin >> C;
		bags.insert(C);
	}

	sort(jewels.begin(), jewels.end(), greater<pair<int, int>>());

	long long sum = 0;
	for (const auto j : jewels) {
		auto m = bags.lower_bound(j.second);

		if (m != bags.end()) {
			sum += j.first;
			bags.erase(m);
		}
	}

	cout << sum << '\n';

	return 0;
}