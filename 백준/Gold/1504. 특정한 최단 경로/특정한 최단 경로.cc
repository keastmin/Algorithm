#include <iostream>
#include <vector>
#include <queue>

#define INF 8000001

using namespace std;

vector<pair<int, int>> graph[801];
vector<int> res(5, 0);
vector<bool> check(5, false);
int mN;

void dijkstra(int s, int e, int w) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(mN + 1, INF);
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (curr == e) {
			res[w] += d;
			check[w] = true;
			return;
		}

		for (const auto g : graph[curr]) {
			int cost = d + g.second;

			if (cost < dist[g.first]) {
				dist[g.first] = cost;
				pq.push({ cost, g.first });
			}
		}
	}
}

int main() {
	int N, E;
	int n1, n2, v1;
	int t1, t2;
	cin >> N >> E;
	mN = N;
	for (int i = 0; i < E; i++) {
		cin >> n1 >> n2 >> v1;
		graph[n1].push_back({ n2, v1 });
		graph[n2].push_back({ n1, v1 });
	}
	cin >> t1 >> t2;

	dijkstra(1, t1, 0);
	dijkstra(t2, N, 1);

	dijkstra(1, t2, 2);
	dijkstra(t1, N, 3);

	dijkstra(t1, t2, 4);

	if (!check[4]) {
		cout << -1 << '\n';
	}
	else if ((check[0] && !check[1]) || (!check[0] && check[1])) {
		if ((check[2] && !check[3]) || (!check[2] && check[3])) {
			cout << -1 << '\n';
		}
	}
	else {
		int r1 = res[0] + res[1] + res[4];
		int r2 = res[2] + res[3] + res[4];
		if (r1 < r2) cout << r1 << '\n';
		else cout << r2 << '\n';
	}

	return 0;
}