#include <iostream>
#include <vector>

using namespace std;

int dp(int x) {
	vector<int> t(x + 1, 0);

	for (int i = 2; i <= x; i++) {
		t[i] = t[i - 1] + 1;
		if (i % 2 == 0)
			t[i] = min(t[i], t[i / 2] + 1);
		if (i % 3 == 0)
			t[i] = min(t[i], t[i / 3] + 1);
	}

	return t[x];
}

int main() {
	int X;
	cin >> X;

	cout << dp(X) << '\n';

	return 0;
}