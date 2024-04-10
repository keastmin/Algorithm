#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int N;
vector<int> graph[100001];
bool visited[100001];
bool finished[100001];
int res;

void dfs(int curr) {
	visited[curr] = true;
	int next = graph[curr][0];

	if (!visited[next])
		dfs(next);
	else {
		if (!finished[next]) {
			for (int i = next; i != curr; i = graph[i][0])
				res++;
			res++;
		}
	}
	finished[curr] = true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		for (int i = 0; i <= 100000; i++) {
			graph[i].clear();
		}
		res = 0;

		cin >> N;
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			graph[i].push_back(a);
		}
		
		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				dfs(i);
		}

		cout << N - res << '\n';
	}

	return 0;
}