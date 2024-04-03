#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int c = 0;
	for (int i = 5; i <= N; i *= 5) {
		c += (N / i);
	}

	cout << c << '\n';

	return 0;
}