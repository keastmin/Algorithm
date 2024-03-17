#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<bool> num(N + 1, false);
	vector<int> arr;
	num[0] = num[1] = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (!num[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				num[j] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!num[i]) {
			//cout << i << ' ';
			arr.push_back(i);
		}
	}

	int s, e, sum, res;
	s = e = sum = res = 0;

	while (true) {
		if (sum > N) {
			sum -= arr[s++];
		}
		else if (sum == N) {
			res++;
			sum -= arr[s++];
		}
		else if (e == arr.size()) break;
		else {
			sum += arr[e++];
		}
	}

	cout << res << '\n';

	return 0;
}