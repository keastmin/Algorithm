#include<iostream>
#include<vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> graph[1001];

void dfs(int current, vector<bool>& visited) {
	visited[current] = true;
	cout << current << ' ';

	for (int i = 0; i < graph[current].size(); i++) {
		int next = graph[current][i];
		if (!visited[next]) {
			dfs(next, visited);
		}
	}
}

void bfs(int start) {
	vector<bool> visited(1001, false);
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << ' ';

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int N, M, S;
	cin >> N >> M >> S;
	vector<int> node;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

		bool checkX = false;
		bool checkY = false;
		for (const auto n : node) {
			if (n == x) checkX = true;
			if (n == y) checkY = true;
		}
		if (!checkX) node.push_back(x);
		if (!checkY) node.push_back(y);
	}
	for (const auto n : node) {
		sort(graph[n].begin(), graph[n].end());
	}

	vector<bool> visited(N + 1, false);
	dfs(S, visited);
	cout << '\n';
	bfs(S);

	return 0;
}