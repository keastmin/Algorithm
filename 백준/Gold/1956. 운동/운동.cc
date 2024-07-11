#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF 1000000000

int V, E;
vector<vector<int>> graph;
int answer = INF;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	graph.resize(V + 1, vector<int>(V + 1, INF));

	for (int i = 1; i <= V; i++) graph[i][i] = 0;
	for (int i = 0; i < E; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		graph[x][y] = c;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) continue;
			answer = min(answer, graph[i][j] + graph[j][i]);
		}
	}

	cout << (answer == INF ? -1 : answer) << '\n';

	return 0;
}