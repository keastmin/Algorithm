#include<iostream>
using namespace std;

int main() {
	int N;
	int count = 0;
	cin >> N;

	while ((N % 5) != 0) {
		N -= 3;
		count++;
	}
	N = N / 5;

	(N >= 0) ? cout << N + count << '\n' : cout << -1 << '\n';


	return 0;
}