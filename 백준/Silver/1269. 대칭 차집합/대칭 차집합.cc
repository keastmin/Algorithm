#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	unordered_map<int, int> A;
	unordered_map<int, int> B;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.insert({ t, 1 });
	}

	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		B.insert({ t, 1 });
	}

	int count = 0;

	for (const auto a : A) {
		if (B[a.first] != 1) {
			count++;
		}
	}

	for (const auto b : B) {
		if (A[b.first] != 1) {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}