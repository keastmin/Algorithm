#include <iostream>
using namespace std;
#define MAX 1000000

long long res[MAX + 1];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	res[1] = 1; res[2] = 2; res[3] = 4;

	for (int i = 4; i <= MAX; i++) {
		res[i] = (res[i - 1] + res[i - 2] + res[i - 3]) % 1000000009;
	}

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		cout << res[N] << '\n';
	}

	return 0;
}