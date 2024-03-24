#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	int res = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			arr[i][j] = a - '0';

			if (arr[i][j] == 1) {
				arr[i][j] = min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1])) + 1;


				res = max(res, arr[i][j] * arr[i][j]);
			}
		}
	}

	cout << res << '\n';

	return 0;
}