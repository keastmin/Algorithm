#include <iostream>
#include <vector>
using namespace std;

int N, M, C;
vector<vector<int>> map;
int dp[51][51][51][51];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> C;
	map.resize(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= C; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = i;
	}

	if (map[1][1] == 0) dp[1][1][0][0]++;
	else dp[1][1][map[1][1]][1]++;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (x == 1 && y == 1) continue;

			if (map[y][x] == 0) {
				for (int i = 0; i <= C; i++) {
					for (int j = 0; j <= C; j++) {
						dp[y][x][j][i] += dp[y - 1][x][j][i] % 1000007;
						dp[y][x][j][i] += dp[y][x - 1][j][i] % 1000007;
					}
				}
			}
			else {
				for (int i = 1; i <= C; i++) {
					for (int j = 0; j < map[y][x]; j++) {
						dp[y][x][map[y][x]][i] += dp[y - 1][x][j][i - 1] % 1000007;
						dp[y][x][map[y][x]][i] += dp[y][x - 1][j][i - 1] % 1000007;
					}
				}
			}
		}
	}

	for (int i = 0; i <= C; i++) {
		int cnt = 0;
		for (int j = 0; j <= C; j++) {
			cnt += dp[N][M][j][i] % 1000007;
		}
		cout << cnt % 1000007 << ' ';
	}

	return 0;
}