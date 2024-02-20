/**********************************************************
2024-02-20
https://github.com/keastmin
백준/15649/N과 M (1)
난이도: 실버 3
유형: 백트래킹
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> res(9);
vector<bool> visited(9);

void iter(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			res[index] = i;
			visited[i] = true;
			iter(n, m, index + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	res.resize(M);
	visited.resize(N + 1, false);

	iter(N, M, 0);

	return 0;
}