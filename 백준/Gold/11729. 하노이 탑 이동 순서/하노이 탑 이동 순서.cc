#include <iostream>
using namespace std;

int N;

void HanoiAlgoiorithm(int from, int by, int to, int num) {
	if (num == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

	HanoiAlgoiorithm(from, to, by, num - 1);
	cout << from << ' ' << to << '\n';
	HanoiAlgoiorithm(by, from, to, num - 1);
}

int main() {
	cin >> N;

	cout << (1 << N) - 1 << '\n';
	HanoiAlgoiorithm(1, 2, 3, N);

	return 0;
}