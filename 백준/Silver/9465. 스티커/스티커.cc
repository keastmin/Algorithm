#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<vector<int>> sticker(2, vector<int>(N + 2, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j <= N + 1; j++) {
				cin >> sticker[i][j];
			}
		}

		for (int i = 2; i <= N + 1; i++) {
			sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
			sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
		}

		cout << max(sticker[0][N + 1], sticker[1][N + 1]) << '\n';
	}

	return 0;
}