#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define INF 987654321
#define IX(i, j) (((i) * (M)) + (j))

vector<string> tmp;
vector<pair<int, int>> maze[10001];
vector<int> wall(10001, INF);

int M, N;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });
	wall[0] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (const auto m : maze[curr]) {
			int c = cost + m.second;

			if (c < wall[m.first]) {
				wall[m.first] = c;
				pq.push({ c, m.first });
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> M >> N;

	tmp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] >= 0 && i + dy[k] < N && j + dx[k] >= 0 && j + dx[k] < M) {
					int cost = tmp[i + dy[k]][j + dx[k]] - '0';
					maze[IX(i, j)].push_back({ IX(i + dy[k], j + dx[k]), cost });
				}
			}
		}
	}
	
	dijkstra();

	cout << wall[M * N - 1] << '\n';


	return 0;
}