#include<iostream>
using namespace std;
int main() {
	int K, A = 1, B = 0, t;
	cin >> K;
	while (K--) { t = A; A = B; B += t; }
	cout << A << ' ' << B;
	return 0;
}