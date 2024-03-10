#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	N = 1000 - N;
	vector<int> en(6);
	en = { 500, 100, 50, 10, 5, 1 };

	int res = 0;
	for (int i = 0; i < 6; i++) {
		int t = N / en[i];
		res += t;
		t *= en[i];
		N -= t;
	}

	cout << res << '\n';

	return 0;
}