#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int N, M;
int set, single;
int res = 0;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	set = numeric_limits<int>::max();
	single = numeric_limits<int>::max();

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		set = min(set, a);
		single = min(single, b);
	}

	res = min({ (N / 6 + 1) * set, (N * single), (N / 6 * set) + (N % 6 * single) });

	cout << res << '\n';

	return 0;
}