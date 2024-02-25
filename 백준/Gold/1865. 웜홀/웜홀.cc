#include <iostream>
#include <vector>
using namespace std;

#define DM 1000000000

struct edge {
	int s, e, d;
};

int N, M, W;

void BellmanFord(vector<edge>& graph, int s) {
	vector<int> distance(N + 1, DM);
	distance[s] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int u = graph[j].s;
			int v = graph[j].e;
			int weight = graph[j].d;
			if (distance[v] > distance[u] + weight) {
				distance[v] = distance[u] + weight;
			}
		}
	}

	for (int i = 0; i < graph.size(); i++) {
		int u = graph[i].s;
		int v = graph[i].e;
		int weight = graph[i].d;
		if (distance[v] > distance[u] + weight) {
			cout << "YES" << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--) {
		cin >> N >> M >> W;
		
		vector<edge> graph;
		int a, b, c;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			
			graph.push_back({ a, b, c });
			graph.push_back({ b, a, c });
		}

		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			graph.push_back({ a, b, -c });
		}

		BellmanFord(graph, 1);
	}

	return 0;
}