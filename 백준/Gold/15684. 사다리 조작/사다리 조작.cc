#include <iostream>
using namespace std;

int N, M, H;
bool ladder_pos[31][11];
int ladder_cnt; // 가로선을 추가할 개수
bool flag = false;

void dfs(int y, int cnt) {
	if (ladder_cnt == cnt) {
		int ver;
		for (int i = 1; i <= N; i++) {
			ver = i;
			for (int j = 1; j <= H; j++) {
				if (ladder_pos[j][ver]) ver++;
				else if (ver > 1 && ladder_pos[j][ver - 1]) ver--;
			}
			if (ver != i) return;
		}
		flag = true;
		return;
	}

	for (int i = y; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (!ladder_pos[i][j - 1] && !ladder_pos[i][j] && !ladder_pos[i][j + 1]) {
				ladder_pos[i][j] = true;
				dfs(i, cnt + 1);
				ladder_pos[i][j] = false;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder_pos[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		ladder_cnt = i;
		dfs(1, 0);
		if (flag) {
			cout << ladder_cnt << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}