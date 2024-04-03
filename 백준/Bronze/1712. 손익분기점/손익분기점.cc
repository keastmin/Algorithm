#include<iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << -1 << '\n';
	}
	else {
		cout << 1 + (A / (C - B)) << '\n';
	}

	return 0;
}