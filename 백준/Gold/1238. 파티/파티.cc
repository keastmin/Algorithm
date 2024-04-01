#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[1001];
vector<int> t;
vector<int> res;

int shortest = INT_MAX;

void dijkstra(int x) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, x });
	t[x] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int value = pq.top().first;
		pq.pop();

		for (const auto g : graph[curr]) {
			int cost = value + g.second;

			if (cost < t[g.first]) {
				t[g.first] = cost;
				pq.push({cost, g.first});
			}
		}
	}
}

void od(int x, int s, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> t2(n + 1, INT_MAX);
	pq.push({ 0, s });
	t2[s] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int value = pq.top().first;
		pq.pop();

		if (curr == x) {
			res[s] = value;
			break;
		}

		for (const auto g : graph[curr]) {
			int cost = value + g.second;

			if (cost < t2[g.first]) {
				t2[g.first] = cost;
				pq.push({ cost, g.first });
			}
		}
	}
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, X;
	cin >> N >> M >> X;
	t.resize(N + 1, INT_MAX);
	res.resize(N + 1, 0);

	int n1, n2, v;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> v;
		graph[n1].push_back({ n2, v });
	}

	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		if (i != X) {
			od(X, i, N);
		}
	}

	for (int i = 1; i <= N; i++) {
		res[i] += t[i];
	}

	sort(res.begin(), res.end(), greater<>());

	cout << res[0] << '\n';

	return 0;
}