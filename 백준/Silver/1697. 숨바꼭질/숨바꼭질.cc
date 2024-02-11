#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> c(100001, false);
vector<int> seconds(100001, 0);

bool check(int n) {
	if (n < 0 || n > 100000) return false;
	else if (c[n]) return false;
	return true;
}

int bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	c[n] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == k) {
			return seconds[current];
		}
		int nm = current - 1;
		int np = current + 1;
		int nt = current * 2;
		if (check(nm)) {
			c[nm] = true;
			q.push(nm);
			seconds[nm] = seconds[current] + 1;
		}
		if (check(np)) {
			c[np] = true;
			q.push(np);
			seconds[np] = seconds[current] + 1;
		}
		if (check(nt)) {
			c[nt] = true;
			q.push(nt);
			seconds[nt] = seconds[current] + 1;
		}
	}
	return 0;
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K) << '\n';

	return 0;
}