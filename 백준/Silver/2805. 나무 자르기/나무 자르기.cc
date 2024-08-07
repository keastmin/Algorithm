#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int low, high;
vector<int> trees;
int res;

void Input() {
	cin >> N >> M;
	trees.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());
	low = 0; high = trees[trees.size() - 1];
}

void Solve() {
	while (low <= high) {
		int cut = (low + high) / 2;
		long long sum = 0;
		
		for (int i = 0; i < trees.size(); i++) {
			if (trees[i] - cut > 0) {
				sum += trees[i] - cut;
			}
		}

		if (sum >= M) {
			res = cut;
			low = cut + 1;
		}
		else {
			high = cut - 1;
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();
	cout << res << '\n';

	return 0;
}