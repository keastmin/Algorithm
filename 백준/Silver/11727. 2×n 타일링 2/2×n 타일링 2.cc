#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> res(N + 1);
	if (N >= 1) res[1] = 1;
	if (N >= 2) res[2] = 3;

	for (int i = 3; i <= N; i++) {
		res[i] = (res[i - 1] + (res[i - 2] * 2)) % 10007;
	}

	cout << res[N] << '\n';

	return 0;
}