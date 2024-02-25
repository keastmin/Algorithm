#include <iostream>
#include <unordered_map>
using namespace std;
#define DIV 1000000007LL
typedef unsigned long long ull;

unordered_map<ull, ull> um;

ull fib(ull n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (um.count(n) > 0) return um[n];

	if (n & 1) {
		ull m1 = (n + 1) / 2;
		ull m2 = (n - 1) / 2;
		return um[n] = (fib(m1) * fib(m1) + fib(m2) * fib(m2)) % DIV;
	}
	ull m = n / 2;
	return um[n] = ((2LL * fib(m - 1) + fib(m)) * fib(m)) % DIV;
}

int main() {
	ull n;
	cin >> n;
	cout << fib(n) << '\n';
	return 0;
}