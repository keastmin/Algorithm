#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> graph;
vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;
}

bool checkParent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	return false;
}

int solution(int e) {
	int minI = 0;
	for (int i = 0; i < e; i++) {
		if (!checkParent(graph[i].second.first, graph[i].second.second)) {
			merge(graph[i].second.first, graph[i].second.second);
			minI += graph[i].first;
		}
	}

	return minI;
}

int main() {
	int V, E, A, B, C;
	cin >> V >> E;
	parent.resize(V + 1);
	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph.push_back({ C, {A, B} });
	}

	sort(graph.begin(), graph.end());

	cout << solution(E) << '\n';

	return 0;
}