#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	unordered_map<long long, bool> um;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		um.insert({ t, true });
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long t;
		cin >> t;
		if (um[t]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}