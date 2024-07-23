#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<int> sorting;

void FindSolution(int cnt) {
	int nextCnt = cnt + 1;

	for (int i = 1; i <= M; i++) {
		sorting[cnt] = i;

		if (nextCnt == N) {
			for (const auto s : sorting) {
				cout << s << ' ';
			}
			cout << '\n';
		}
		else {
			FindSolution(nextCnt);
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	sorting.resize(N);

	FindSolution(0);

	return 0;
}