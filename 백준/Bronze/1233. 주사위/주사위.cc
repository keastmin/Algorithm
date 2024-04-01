#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> res;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				res.push_back(i + j + k);
			}
		}
	}

	int max_r = 0;
	int answer = 0;
	unordered_map<int, int> cnt;
	for (const auto r : res) {
		cnt[r]++;

		if (cnt[r] > max_r) {
			max_r = cnt[r];
			answer = r;
		}
	}

	cout << answer << '\n';

	return 0;
}