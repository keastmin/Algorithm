#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sum;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	sum.resize(N + 1, 0);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sum[i + 1] = sum[i] + a;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	return 0;
}