/**********************************************************
2024-04-09
https://github.com/keastmin
백준/5543/상근날드
난이도: 브론즈4
유형: 수학
**********************************************************/

#include <iostream>
using namespace std;

int main() {
	int burger[3];
	int drink[2];

	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
	}

	int res = 5000;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = burger[i] + drink[j] - 50;
			if (res > sum) {
				res = sum;
			}
		}
	}

	cout << res << '\n';

	return 0;
}