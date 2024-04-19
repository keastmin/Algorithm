#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cage;

int main() {
	cin >> N;
	cage.resize(N + 1, 0);
	cage[0] = 1;
	cage[1] = 3;

	for (int i = 2; i <= N; i++) {
		cage[i] = (cage[i - 1] * 2 + cage[i - 2]) % 9901;
	}

	cout << cage[N] % 9901 << '\n';

	return 0;
}