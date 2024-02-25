#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];
int farth;
int maxDist;

void dfs(int s, int dist) {
	if (dist > maxDist) {
		maxDist = dist;
		farth = s;
	}
	visited[s] = true;

	for (const auto g : graph[s]) {
		if (!visited[g.first]) {
			dfs(g.first, dist + g.second);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a, c });
	}

	maxDist = 0;
	dfs(1, 0);

	fill(begin(visited), end(visited), false);
	maxDist = 0;
	dfs(farth, 0);

	cout << maxDist;

	return 0;
}