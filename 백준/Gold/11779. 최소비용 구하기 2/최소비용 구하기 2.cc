#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

vector<pair<int, ll>> graph[1001];
vector<vector<int>> memo;
vector<ll> value;

int N, M, s, e;

void dijkstra() {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({ 0, s });
	value[s] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		ll exp = pq.top().first;
		pq.pop();
		memo[curr].push_back(curr);
		if (curr == e) break;

		for (const auto g : graph[curr]) {
			ll cost = exp + g.second;

			if (cost < value[g.first]) {
				value[g.first] = cost;
				pq.push({ cost, g.first });
				memo[g.first] = memo[curr];
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	value.resize(N + 1, 1e9);
	memo.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int x, y;
		ll v;
		cin >> x >> y >> v;
		graph[x].push_back({ y, v });
	}

	cin >> s >> e;

	dijkstra();

	cout << value[e] << '\n';
	cout << memo[e].size() << '\n';
	for (const auto m : memo[e]) {
		cout << m << ' ';
	}

	return 0;
}