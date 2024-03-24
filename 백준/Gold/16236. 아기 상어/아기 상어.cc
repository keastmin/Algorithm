#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N;
vector<vector<int>> map;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int sX, sY;
int sSize = 2;
int sEatCnt = 0;
int res;

bool check(int x, int y, vector<vector<bool>>& v) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    else if (v[y][x]) return false;
    else if (map[y][x] > sSize) return false;
    return true;
}

int bfs() {
    int d = INT_MAX;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    q.push({ {sX, sY}, 0 });
    visited[sY][sX] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        //cout << x << ' ' << y << ' ' << dist << '\n';
        q.pop();

        if (map[y][x] < sSize && map[y][x] != 0) {
            if (d > dist) {
                d = dist;
                sX = x; sY = y;
            }
            else if (d == dist) {
                if (sY > y) {
                    sX = x; sY = y;
                }
                else if (sY == y) {
                    if (sX > x) {
                        sX = x; sY = y;
                    }
                }
            }
            else {
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny, visited)) {
                q.push({ {nx, ny}, dist + 1 });
                visited[ny][nx] = true;
            }
        }
    }

    return d;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                map[i][j] = 0;
                sX = j; sY = i;
            }
        }
    }

    int a = 10;
    int idx = 0;
    while (true) {
        //cout << "작동" << idx++ << '\n';
        int d = bfs();
        if (d == INT_MAX) break;
        map[sY][sX] = 0;
        res += d;

        sEatCnt++;
        if (sEatCnt == sSize) {
            sSize++;
            sEatCnt = 0;
        }
    }

    cout << res << '\n';

    return 0;
}