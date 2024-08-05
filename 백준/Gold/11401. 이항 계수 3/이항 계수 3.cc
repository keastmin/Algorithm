#include <iostream>
using namespace std;

#define DIV 1000000007

int N, K;
long long tmp;

long long power(long long a, long long m) {
	if (m == 0) return 1;

	tmp = power(a, m / 2) % DIV;
	if (m % 2 == 1) return tmp * tmp % DIV * a % DIV;
	return tmp * tmp % DIV;
}

// 페르마의 소정리를 통해 B^(-1) % P = B^(P - 2) % P가 된다.
void Binomial_Coefficient(int n, int k) {
	long long A = 1, B = 1, res = 0;
	for (int i = n; i >= n - k + 1; i--) A = (A * i) % DIV;
	for (int i = k; i > 1; i--) B = (B * i) % DIV;
	res = ((A % DIV) * power(B, DIV - 2) % DIV) % DIV;
	cout << res << '\n';
}

int main() {
	cin >> N >> K;
	Binomial_Coefficient(N, K);

	return 0;
}