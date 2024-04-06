#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MODUL 1000000

string code;
vector<int> cache;

int Possible(int idx) {
	if (code[idx] == '0') {
		return 0;
	}
	else if (code[idx] == '1') {
		if ((idx + 1) < code.size()) {
			return 2;
		}
	}
	else if (code[idx] == '2') {
		if ((code[idx + 1] <= '6') && (idx + 1 < code.size())) {
			return 2;
		}
	}
	return 1;
}

int dp(int idx) {
	if (idx >= code.size()) return 1;
	int& ret = cache[idx];
	if (ret != -1) return ret;

	ret = 0;
	int possible = Possible(idx);

	for (int i = 1; i <= possible; i++) {
		if (i == 1) ret = dp(idx + i) % MODUL;
		else ret = (ret + dp(idx + i)) % MODUL;
	}

	return ret %= MODUL;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> code;
	cache.resize(code.size(), -1);

	cout << dp(0) << '\n';

	return 0;
}