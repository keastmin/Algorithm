#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];

int bfs(int s, int e, int N) {
	int cnt = 0;
	queue<int> q;
	vector<int> visited(N, false);
	q.push(s);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == e && cnt > 0) return 1;

		for (const auto g : graph[curr]) {
			if (!visited[g]) {
				visited[g] = true;
				q.push(g);
			}
		}
		cnt++;
	}

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			if (t == 1) {
				graph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(j < N - 1)
				cout << bfs(i, j, N) << ' ';
			else
				cout << bfs(i, j, N);
		}
		cout << '\n';
	}

	return 0;
}