#include <iostream>
using namespace std;

int cnt = 0;
int N;

int main() {
	cin >> N;

	while ((N % 5) != 0) {
		N -= 3;
		cnt++;
	}
	N /= 5;

	(N >= 0) ? cout << N + cnt << '\n' : cout << -1 << '\n';

	return 0;
}