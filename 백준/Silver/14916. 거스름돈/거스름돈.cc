#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;

	int tmp = N;
	int res = 0;

	while (tmp % 5 != 0 && tmp >= 2) {
		tmp -= 2;
		res++;
	}

	res += (tmp / 5);
	tmp = (tmp % 5);

	if (tmp > 0) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}