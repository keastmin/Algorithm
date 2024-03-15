#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];

int bfs(int n, int s, int e) {
	queue<pair<int, int>> q;
	vector<bool> visited(n + 1, false);
	q.push({ s, 0 });
	visited[s] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == e)
			return dist;

		for (const auto g : graph[curr]) {
			if (!visited[g]) {
				visited[g] = true;
				q.push({ g, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, s, e;
	cin >> N >> s >> e >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(N, s, e) << '\n';

	return 0;
}