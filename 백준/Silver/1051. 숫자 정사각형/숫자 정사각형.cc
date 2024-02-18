#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int x, int y, int k, vector<string> m) {
	if (m[y][x] == m[y][x + k] && m[y][x] == m[y + k][x] && m[y][x] == m[y + k][x + k])
		return true;
	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	vector<int> res;
	int minI = (N < M) ? N : M;
	for (int k = 0; k < minI; k++) {
		for (int i = 0; i < N - k; i++) {
			for (int j = 0; j < M - k; j++) {
				if (check(j, i, k, map)) {
					int l = k + 1;
					res.push_back(l * l);
				}
			}
		}
	}


	sort(res.begin(), res.end(), greater<>());
	cout << res[0] << '\n';


	return 0;
}