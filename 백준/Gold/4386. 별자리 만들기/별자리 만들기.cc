#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector<pair<float, float>> stars;
vector<pair<int, float>> dists[100];
vector<bool> visited;

float res = 0;

float GetDistance(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void FindMinimumStarsDist() {
	priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
	for (const auto& d : dists[0]) {
		int next = d.first;
		float dist = d.second;
		pq.push({ dist, next });
	}
	visited[0] = true;

	while (!pq.empty()) {
		float dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (!visited[curr]) {
			visited[curr] = true;
			res += dist;

			for (const auto& d : dists[curr]) {
				int next = d.first;
				float nDist = d.second;
				if(!visited[next]) pq.push({ nDist, next });
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);

	cin >> N;
	stars.resize(N);
	visited.resize(N, false);
	for (int i = 0; i < N; i++) {
		cin >> stars[i].first >> stars[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			float dist = GetDistance(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
			dists[i].push_back({ j, dist });
			dists[j].push_back({ i, dist });
		}
	}

	FindMinimumStarsDist();
	cout << res << '\n';

	return 0;
}