#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sorting;

void Back(int curr, int idx) {
	if (idx == M) {
		for (const auto s : sorting) {
			cout << s << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = curr; i <= N; i++) {
		sorting[idx] = i;
		Back(i, idx + 1);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	sorting.resize(M);
	
	for (int i = 1; i <= N; i++) {
		sorting[0] = i;
		Back(i, 1);
	}

	return 0;
}