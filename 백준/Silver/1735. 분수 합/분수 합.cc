#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	ll A1, B1;
	ll A2, B2;
	cin >> A1 >> B1 >> A2 >> B2;
	A1 *= B2;
	A2 *= B1;
	A1 += A2;
	B1 *= B2;
	ll s = gcd(A1, B1);

	cout << A1 / s << ' ' << B1 / s << '\n';

	return 0;
}