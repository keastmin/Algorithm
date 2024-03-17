#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int arr[100000];
	int N, S;
	int s, e, sum, ans;
	s = e = sum = 0;
	cin >> N >> S;
	ans = N + 1;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	while (true) {
		if (sum >= S) {
			ans = min(ans, e - s);
			sum -= arr[s++];
		}
		else if(e == N) {
			break;
		}
		else {
			sum += arr[e++];
		}

		if (s > e) {
			cout << 1 << '\n';
			return 0;
		}
	}

	if (ans == N + 1) cout << 0 << '\n';
	else cout << ans << '\n';

	return 0;
}