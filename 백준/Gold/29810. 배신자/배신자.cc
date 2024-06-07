#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, X;
vector<int> friends[200001];
vector<bool> visited;
int res = 0;

int FindMaxNumber(int num) {
	int cnt = 0;
	int cycle = 0;
	stack<int> s;
	s.push(num);
	visited[num] = true;

	while (!s.empty()) {
		int curr = s.top();
		s.pop();
		cnt++;

		for (const auto& g : friends[curr]) {
			if (g == X) cycle++;
			else if (!visited[g]) {
				s.push(g);
				visited[g] = true;
			}
		}
	}

	if (cycle == 1) cnt++;
	//cout << cnt << '\n';
	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	visited.resize(N + 1, false);
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		friends[n1].push_back(n2);
		friends[n2].push_back(n1);
	}
	cin >> X;

	visited[X] = true;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			res = max(res, FindMaxNumber(i));
		}
	}

	cout << res << '\n';

	return 0;
}