#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull A, B, C;
ull calc(ull b) {
	if (b == 1) return A % C;

	ull K = calc(b / 2) % C;
	if (b % 2 == 0) return K * K % C;
	return K * K % C * A % C;
}

int main() {
	cin >> A >> B >> C;

	ull res = calc(B);

	cout << res << '\n';

	return 0;
}