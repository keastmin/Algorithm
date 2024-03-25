#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int N, M;
vector<pair<int, int>> graph[100001];
vector<int> value;

int res = 0;
int ma = 0;

void prim() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> visited(N + 1, false);

	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (visited[curr]) continue;
		visited[curr] = true;
		res += cost;
		ma = max(ma, cost);
		//value[curr] = res;
		//cout << res << ' ' << cost << '\n';

		for (const auto g : graph[curr]) {
			if (!visited[g.first]) {
				pq.push({ g.second, g.first });
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	value.resize(N + 1, numeric_limits<int>::max());

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	prim();

	//for (int i = 1; i <= N; i++) {
	//	cout << value[i] << '\n';
	//}

	cout << res - ma << '\n';

	return 0;
}