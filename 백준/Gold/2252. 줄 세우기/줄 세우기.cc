#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[32001];
vector<int> line[32001];

void topologySort() {
	int result[32001];
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		int curr = q.front();
		q.pop();
		result[i] = curr;

		for (const auto l : line[curr]) {
			int x = l;
			if (--inDegree[x] == 0) {
				q.push(x);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		inDegree[b]++;
	}

	topologySort();

	return 0;
}