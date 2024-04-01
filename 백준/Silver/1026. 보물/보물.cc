#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (A[i] * B[i]);
	}
	cout << sum << '\n';
	return 0;
}