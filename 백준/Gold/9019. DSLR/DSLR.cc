#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int T;

int D(int n) {
	return (2 * n) % 10000;
}

int S(int n) {
	return (n == 0) ? 9999 : (n - 1);
}

int L(int n) {
	return (n % 1000) * 10 + n / 1000;
}

int R(int n) {
	return (n % 10) * 1000 + n / 10;
}

string bfs(int s, int e) {
	string res = "";
	queue<pair<int, string>> q;
	vector<bool> visited(10000, false);
	q.push({ s, res });
	visited[s] = true;

	//cout << '\n';
	while (!q.empty()) {
		int curr = q.front().first;
		string str = q.front().second;
		q.pop();

		//cout << curr << '\n';

		if (curr == e) {
			res = str;
			break;
		}

		int d = D(curr);
		int s = S(curr);
		int l = L(curr);
		int r = R(curr);

		if (!visited[d]) {
			q.push({ d, str + "D"});
			visited[d] = true;
		}
		if (!visited[s]) {
			q.push({ s, str + "S" });
			visited[s] = true;
		}
		if (!visited[l]) {
			q.push({ l, str + "L" });
			visited[l] = true;
		}
		if (!visited[r]) {
			q.push({ r, str + "R" });
			visited[r] = true;
		}
	}
	//cout << '\n';

	return res;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;

		cout << bfs(A, B) << '\n';
	}

	return 0;
}