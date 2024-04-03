#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int N, E;
vector<int> graph[20001];
int color[20001];

void dfs() {
	vector<bool> visited(N + 1, false);

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			stack<pair<int, int>> s;
			s.push({ i, 0 });
			color[i] = 0;
			visited[i] = true;

			while (!s.empty()) {
				int curr = s.top().first;
				int t = s.top().second;
				int nt = (t == 0) ? 1 : 0;
				s.pop();

				for (const auto g : graph[curr]) {
					if (!visited[g]) {
						visited[g] = true;
						color[g] = nt;
						s.push({ g, nt });
					}
				}
			}
		}
	}
}

string check() {
	for (int i = 1; i <= N; i++) {
		for (const auto g : graph[i]) {
			if (color[g] == color[i]) {
				return "NO";
			}
		}
	}

	return "YES";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int K;
	cin >> K;
	while (K--) {
		cin >> N >> E;

		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		dfs();
		cout << check() << '\n';

		for (int i = 0; i <= 20000; i++) {
			graph[i].clear();
		}
	}

	return 0;
}