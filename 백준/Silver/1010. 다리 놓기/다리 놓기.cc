#include<iostream>
using namespace std;

int main() {
	int T;
	int N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin >> M;

		int result = 1;

		for (int j = 0; j < N; j++) {
			result *= M - j;
			result /= j + 1;
		}

		cout << result << '\n';
	}

	return 0;
}