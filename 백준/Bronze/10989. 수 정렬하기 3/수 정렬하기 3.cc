#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count[10000] = { 0 };

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		count[tmp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				cout << i + 1 << '\n';
			}
		}
	}

	return 0;
}