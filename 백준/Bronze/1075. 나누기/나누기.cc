#include<iostream>
using namespace std;

int main() {
	int n;
	int f;
	int res;
	cin >> n;
	cin >> f;
	res = (n / 100) * 100;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int tmp = res + (i * 10) + j;
			if (tmp % f == 0) {
				cout << i << j << endl;
				return 0;
			}
		}
	}

	return 0;
}