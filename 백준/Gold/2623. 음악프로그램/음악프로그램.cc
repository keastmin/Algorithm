#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> inDegree;
vector<int> res;
vector<int> graph[1001];

void TopologySort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			return;
		}

		int curr = q.front();
		q.pop();
		res.push_back(curr);

		for (const auto g : graph[curr]) {
			inDegree[g]--;
			if (inDegree[g] == 0) {
				q.push(g);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	inDegree.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int iter, prev, curr;
		cin >> iter >> prev;

		for (int j = 0; j < iter - 1; j++) {
			cin >> curr;

			inDegree[curr]++;
			graph[prev].push_back(curr);
			prev = curr;
		}
	}
	TopologySort();
	//for (int i = 1; i <= N; i++) {
	//	cout << inDegree[i] << '\n';
	//}

	if (res.size() < N) {
		cout << 0 << '\n';
	}
	else {
		for (const auto r : res) {
			cout << r << '\n';
		}
	}

	return 0;
}