#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<int, ll>> graph[100001];
vector<bool> visited(100001, false);
int farth;
ll maxDist;

void dfs(int s, ll dist) {
	visited[s] = true;
	if (dist > maxDist) {
		maxDist = dist;
		farth = s;
	}

	for (const auto g : graph[s]) {
		if (!visited[g.first]) {
			dfs(g.first, dist + g.second);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int V;
	cin >> V;

	for (int i = 0; i < V; i++) {
		int curr;
		cin >> curr;

		while (true) {
			int n, d;
			cin >> n;
			if (n == -1) break;
			cin >> d;

			graph[curr].push_back({ n, d });
		}
	}

	maxDist = 0;
	dfs(1, 0);

	fill(begin(visited), end(visited), false);
	maxDist = 0;
	dfs(farth, 0);

	cout << maxDist;

	return 0;
}