#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[20001];
int value[20001];

void dijkstra(int K, int V) {
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	pq.push({ value[K], K });

	while (!pq.empty()) {
		int curr = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (val > value[curr]) continue;

		for (const auto g : graph[curr]) {
			int v = g.first;
			int w = g.second;

			if (val + w < value[v]) {
				value[v] = val + w;
				pq.push({ val + w, v });
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int V, E, K;
	int u, v, w;
	cin >> V >> E >> K;
	for (int i = 1; i <= V; i++) value[i] = INF;
	value[K] = 0;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	dijkstra(K, V);

	for (int i = 1; i <= V; i++) {
		if (value[i] == INF) cout << "INF" << '\n';
		else cout << value[i] << '\n';
	}

	return 0;
}