#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> inDeg;
vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	inDeg.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		inDeg[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();
		cout << curr << ' ';

		for (const auto g : graph[curr]) {
			inDeg[g]--;

			if (inDeg[g] == 0) {
				pq.push(g);
			}
		}
	}

	return 0;
}