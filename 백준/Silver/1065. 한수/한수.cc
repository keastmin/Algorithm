#include<iostream>
using namespace std;

int Han(int a);

int main() {
	int N;
	cin >> N;
	cout << Han(N) << '\n';
	return 0;
}

int Han(int a) {
	int count = 0;
	for (int i = 1; i <= a; i++) {
		if (i < 100)
			count++;
		else {
			int ref_count = 0;
			int hs = i;
			int k[4];
			while (hs != 0) {
				k[ref_count++] = hs % 10;
				hs = hs / 10;
			}
			if (i < 1000) {
				if ((k[0] - k[1]) == (k[1] - k[2]))
					count++;
			}
		}
	}

	return count;
}