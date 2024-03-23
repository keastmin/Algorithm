#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> grade(N);

		for (int i = 0; i < N; i++) {
			cin >> grade[i].first >> grade[i].second;
		}

		sort(grade.begin(), grade.end());

		//cout << '\n';
		//for (const auto g : grade) {
		//	cout << g.first << ' ' << g.second << '\n';
		//}

		int res = 1;
		int m = grade[0].second;

		for (int i = 1; i < N; i++) {
			if (m > grade[i].second) {
				res++;
				m = grade[i].second;
			}
		}

		cout << res << '\n';
	}

	return 0;
}