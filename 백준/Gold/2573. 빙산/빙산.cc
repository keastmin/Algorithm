#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void melt() {
    vector<vector<int>> temp(N, vector<int>(M, 0));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] != 0) {
                int water = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 0) {
                        water++;
                    }
                }
                temp[y][x] = max(0, map[y][x] - water);
            }
        }
    }
    map = temp;
}

bool isSeparated() {
    visited.assign(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    int iceberg = 0, visitedIcebergs = 0;

    for (int y = 0; y < N && q.empty(); y++) {
        for (int x = 0; x < M && q.empty(); x++) {
            if (map[y][x] > 0) {
                q.push({ x, y });
                visited[y][x] = true;
                break;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        visitedIcebergs++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] > 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ nx, ny });
            }
        }
    }

    // 전체 빙산 개수 세기
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] > 0) iceberg++;
        }
    }

    // 방문한 빙산 개수와 전체 빙산 개수 비교
    return visitedIcebergs != iceberg;
}

int main() {
    cin >> N >> M;
    map.assign(N, vector<int>(M, 0));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    int year = 0;
    while (true) {
        if (isSeparated()) {
            cout << year << "\n";
            break;
        }

        melt();
        year++;

        bool allMelted = true;
        for (int y = 0; y < N && allMelted; y++) {
            for (int x = 0; x < M && allMelted; x++) {
                if (map[y][x] > 0) {
                    allMelted = false;
                }
            }
        }

        if (allMelted) {
            cout << 0 << "\n";
            break;
        }
    }

    return 0;
}