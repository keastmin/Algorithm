#include <iostream>
using namespace std;

int L, P, V;
int cnt = 1;

int main() {
	while (true) {
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		int res = 0;
		while (V > 0) {
			if (V >= L) res += L;
			else res += V;
			V -= P;
		}

		cout << "Case " << cnt++ << ": " << res << '\n';
	}

	return 0;
}