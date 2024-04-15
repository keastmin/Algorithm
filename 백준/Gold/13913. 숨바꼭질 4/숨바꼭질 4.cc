#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, m;
vector<int> prevPos;
vector<bool> visited;

int bfs() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (curr == K) return sec;

		int n[3] = { curr - 1, curr + 1, curr * 2 };

		for (int i = 0; i < 3; i++) {
			if (n[i] >= 0 && n[i] <= (m + 2)) {
				if (!visited[n[i]]) {
					visited[n[i]] = true;
					prevPos[n[i]] = curr;
					q.push({ n[i], sec + 1 });
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;
	m = max(N, K);
	prevPos.resize(m + 3, -1);
	visited.resize(m + 3, false);

	int res = bfs();
	cout << res << '\n';

	vector<int> seq;
	seq.push_back(K);

	while (prevPos[K] != -1) {
		seq.push_back(prevPos[K]);
		K = prevPos[K];
	}

	for (int i = seq.size() - 1; i >= 0; i--) {
		if (i == 0) cout << seq[i];
		else 		cout << seq[i] << ' ';
	}

	return 0;
}