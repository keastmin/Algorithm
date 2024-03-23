#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

// 전체 공간
int map[301][301];

// 빙산이 있던 위치
// first.first = x, first.second = y, second = 주변 0의 개수
pair<pair<int, int>, int> pos[10001];

// 빙산이 존재하는 수
int idx = 0;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

// 모두 녹은 빙산이 있는지 감지
bool detecZ = false;
bool allZ = false;

// x, y가 범위를 넘어가지 않는지 검사
bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	return true;
}

// 빙산 주변의 0을 체크
void countZ() {
	allZ = true;
	for (int i = 0; i < idx; i++) {
		int x = pos[i].first.first;
		int y = pos[i].first.second;
		
		// 빙산 주변 0의 개수를 0개로 초기화
		pos[i].second = 0;

		if (map[y][x] != 0) {
			allZ = false;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (check(nx, ny)) {
					if (map[ny][nx] == 0) {
						pos[i].second++;
					}
				}
			}
		}
	}
}

// 주변의 바다의 개수만큼 빙산의 높이를 감소 시키는 함수
void minusZ() {
	for (int i = 0; i < idx; i++) {
		int x = pos[i].first.first;
		int y = pos[i].first.second;

		if (map[y][x] != 0) {
			map[y][x] -= pos[i].second;

			// 감소 후 0보다 작아졌다면 0으로 맞추고 0이 된 빙산이 있음을 감지하는 변수를 true로 설정
			if (map[y][x] <= 0) {
				map[y][x] = 0;
				detecZ = true;
			}
		}
	}
}

// 빙산을 bfs 하며 2번째 bfs가 실행되면 두 개의 빙산이 있을을 알림
bool bfs() {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	int cnt = 0; // bfs의 횟수 누적

	for (int i = 0; i < idx; i++) {
		int x = pos[i].first.first;
		int y = pos[i].first.second;

		if (map[y][x] != 0 && !visited[y][x]) {
			if (2 == ++cnt) return true;

			queue<pair<int, int>> q;
			q.push({ x, y });
			visited[y][x] = true;

			// bfs 시작
			while (!q.empty()) {
				int cx = q.front().first;
				int cy = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];

					if (check(nx, ny)) {
						if (map[ny][nx] != 0 && !visited[ny][nx]) {
							q.push({ nx, ny });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
	}

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			
			// 빙산이 존재하는 위치만 따로 저장
			if (map[i][j] != 0)
				pos[idx++] = {{ j, i }, 0 };
		}
	}

	// 주변의 바다 개수 카운트
	countZ();

	int res = 0;
	while (true) {
		// 주변의 바다 개수만큼 높이 감소
		minusZ();
		res++;

		// 빙산을 bfs하며 두개로 분리 되었는지 확인
		if (bfs()) {
			cout << res << '\n';
			break;
		}

		// 분리되지 않았고 빙산의 높이가 0이 된 것이 감지 되었다면 다시 빙산 주변의 바다 개수 카운트
		if (detecZ) {
			countZ();
			detecZ = false;
		}

		if (allZ) {
			cout << 0 << '\n';
			break;
		}
	}

	return 0;
}