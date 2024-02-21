#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[101];
vector<int> item;

int N, M, R;
int sum = 0;

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> value(N + 1, 1e9);
	vector<bool> check(N + 1, false);
	int r = 0;
	pq.push({ 0, s });
	value[s] = 0;
	
	while (!pq.empty()) {
		int curr = pq.top().second;
		int v = pq.top().first;
		check[curr] = true;
		pq.pop();

		for (const auto g : graph[curr]) {
			int dist = v + g.second;

			if (dist < value[g.first]) {
				value[g.first] = dist;
				if (value[g.first] <= M) {
					pq.push({ dist, g.first });
				}
			}
		}		
	}

	//for (const auto c : check) {
	//	cout << c << ' ';
	//}
	//cout << '\n';

	for (int i = 1; i < N + 1; i++) {
		if (check[i])
			r += item[i];
	}

	if (r > sum)
		sum = r;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	item.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < R; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		graph[x].push_back({ y, v });
		graph[y].push_back({ x, v });
	}

	for (int i = 1; i <= N; i++)
		dijkstra(i);

	cout << sum << '\n';

	return 0;
}