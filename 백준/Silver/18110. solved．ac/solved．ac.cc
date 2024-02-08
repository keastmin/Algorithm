#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> nan(N);

	if (N == 0) {
		cout << 0 << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> nan[i];
		}
		sort(nan.begin(), nan.end());

		double j = N * (30.0 / 200.0);
		int h = (j - (int)j >= 0.5) ? (int)j + 1 : (int)j;
		
		double sum = 0.0;
		for (int i = h; i < N - h; i++) {
			sum += nan[i];
		}
		sum /= (N - h * 2);
		int res = (sum - (int)sum >= 0.5) ? (int)sum + 1 : (int)sum;
		cout << res << '\n';
	}

	return 0;
}