#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	ll K, N;
	cin >> K >> N;
	vector<ll> lan(K);
	ll maxL = 0;
	for (ll i = 0; i < K; i++) {
		cin >> lan[i];
		if (maxL < lan[i]) {
			maxL = lan[i];
		}
	}

	ll left = 1, right = maxL;
	ll res = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll count = 0;
		for (const auto l : lan) {
			count += l / mid;
		}
		if (count >= N) {
			res = max(res, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << res << '\n';

	return 0;
}