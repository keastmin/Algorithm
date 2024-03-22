#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
typedef unsigned long long ull;
ull A, B;
unordered_map<ull, bool> visited;

int bfs() {
	queue<pair<ull, int>> q;
	q.push({ A, 1 });
	visited[A] = true;

	while (!q.empty()) {
		ull curr = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (curr == B) return cnt;

		if (curr < B) {
			if (!visited[curr * 2]) {
				visited[curr * 2] = true;
				q.push({ curr * 2, cnt + 1 });
			}
			if (!visited[(curr * 10) + 1]) {
				visited[(curr * 10) + 1] = true;
				q.push({ (curr * 10) + 1, cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> A >> B;
	cout << bfs() << '\n';
	return 0;
}