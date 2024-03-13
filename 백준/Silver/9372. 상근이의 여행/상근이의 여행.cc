#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(int N, vector<int> graph[]) {
	stack<int> s;
	vector<int> visited(1001, false);
	s.push(1);
	visited[1] = true;
	int res = -1;

	while (!s.empty()) {
		int curr = s.top();
		s.pop();
		res++;

		for (const auto g : graph[curr]) {
			if (!visited[g]) {
				s.push(g);
				visited[g] = true;
			}
		}
	}
	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> graph[1001];
		int N, M;
		cin >> N >> M;

		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		cout << dfs(N, graph) << '\n';
	}
	return 0;
}