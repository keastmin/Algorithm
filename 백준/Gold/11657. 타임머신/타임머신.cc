#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> graph;
vector<long long> result;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	result.resize(N + 1, numeric_limits<int>::max());
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph.push_back({ c, { a, b } });
	}

	result[1] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int s = graph[j].second.first;
			int e = graph[j].second.second;
			int d = graph[j].first;

			if (result[s] == numeric_limits<int>::max()) continue;
			if (result[e] > result[s] + d) result[e] = result[s] + d;
		}
	}

	for (int i = 0; i < graph.size(); i++) {
		int s = graph[i].second.first;
		int e = graph[i].second.second;
		int d = graph[i].first;

		if (result[s] == numeric_limits<int>::max()) continue;
		if (result[e] > result[s] + d) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (result[i] == numeric_limits<int>::max()) cout << -1 << '\n';
		else cout << result[i] << '\n';		
	}

	return 0;
}