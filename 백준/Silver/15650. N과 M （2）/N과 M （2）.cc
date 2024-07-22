#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<bool> visited;
vector<int> sorting;

void FindSolution(int curr, int cnt) {
	if (cnt == N) {
		for (const auto s : sorting) {
			cout << s << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = curr + 1; i <= M; i++) {
		visited[i] = true;
		sorting[cnt] = i;
		FindSolution(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	visited.resize(M + 1, false);
	sorting.resize(N);

	for (int i = 1; i <= M; i++) {
		visited[i] = true;
		sorting[0] = i;
		FindSolution(i, 1);
		visited[i] = false;
	}

	return 0;
}