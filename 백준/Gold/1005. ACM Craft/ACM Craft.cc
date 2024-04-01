#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[1002];
vector<int> delay;
vector<int> inDeg;
vector<int> res;

void BFS(int N) {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
		}
		res[i] = delay[i];
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (const auto g : graph[curr]) {
			inDeg[g]--;
			res[g] = max(res[g], res[curr] + delay[g]);

			if (inDeg[g] == 0) {
				q.push(g);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, K, X, Y, W;
		cin >> N >> K;
		for (int j = 0; j < 1002; j++) {
			graph[j].clear();
		}
		delay.resize(N + 2, 0);
		inDeg.resize(N + 2, 0);
		res.resize(N + 2, 0);
		for (int j = 1; j <= N; j++) {
			cin >> delay[j];
		}
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			graph[X].push_back(Y);
			inDeg[Y]++;
		}
		cin >> W;
		BFS(N);

		cout << res[W] << '\n';
	}

	return 0;
}