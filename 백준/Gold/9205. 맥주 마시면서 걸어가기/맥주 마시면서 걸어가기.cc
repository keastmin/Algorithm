#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int T, N;
int sX, sY, eX, eY;

string bfs(vector<pair<int, int>>& conven) {
	queue<pair<int, int>> q;
	vector<bool> visited(N, false);
	q.push({ sX, sY });

	while (!q.empty()) {
		double x = q.front().first;
		double y = q.front().second;
		q.pop();

		double dist = abs(eX - x) + abs(eY - y);
		//cout << dist << '\n';
		if (dist <= 1000) {
			return "happy";
		}

		for (int i = 0; i < conven.size(); i++) {
			if (visited[i]) continue;

			double cX = conven[i].first;
			double cY = conven[i].second;
			dist = abs(cX - x) + abs(cY - y);

			if (dist <= 1000) {
				q.push({ (int)cX, (int)cY });
				visited[i] = true;
			}
		}
	}

	return "sad";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> sX >> sY;
		vector<pair<int, int>> conven(N);
		for (int i = 0; i < N; i++) {
			cin >> conven[i].first >> conven[i].second;
		}
		cin >> eX >> eY;

		cout << bfs(conven) << '\n';
	}

	return 0;
}