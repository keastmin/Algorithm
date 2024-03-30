#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> parents;

int N, M;

int Find(int x) {
	if (parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y) parents[y] = x;
	else parents[x] = y;
}

string result() {
	int res;
	cin >> res;
	res = parents[res];

	for (int i = 1; i < M; i++) {
		int plan;
		cin >> plan;
		plan = parents[plan];

		if (res != plan) {
			return "NO";
		}
	}

	return "YES";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	parents.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		parents[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int t;
			cin >> t;

			if (t == 1) {
				Union(i, j);
			}
		}
	}

	//for (const auto p : parents) {
	//	cout << p << ' ';
	//}
	//cout << '\n';


	cout << result() << '\n';

	return 0;
}