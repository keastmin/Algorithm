#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpii;

int N, M;
vvi map;
vpii house;
vpii chicken;
int res = 10000;

void FindMinDistance(string bin) {
	//cout << "진입" << '\n';
	//cout << bin << '\n';

	vpii tmp;
	int sum = 0;
	for (int i = 0; i < bin.length(); i++) {
		if (bin[i] == '1') {
			tmp.push_back(chicken[i]);
		}
	}

	for (const auto& h : house) {
		int dist = 10000;
		for (const auto& t : tmp) {
			dist = min(dist, abs(h.first - t.first) + abs(h.second - t.second));
		}
		sum += dist;
	}

	res = min(res, sum);
	//cout << res << '\n';
}

void SelectChicken(int curr, string bin, int cnt) {
	bin[curr] = '1';
	
	if (cnt == M - 1) {
		FindMinDistance(bin);
		return;
	}

	for (int i = curr + 1; i < chicken.size(); i++) {
		SelectChicken(i, bin, cnt + 1);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map.resize(N + 1, vi(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 1) house.push_back({ r, c });
			else if (map[r][c] == 2) chicken.push_back({ r,c });
		}
	}

	string binary = "";
	for (int i = 0; i < chicken.size(); i++) binary += "0";
	for (int i = 0; i < chicken.size(); i++) SelectChicken(i, binary, 0);
	cout << res << '\n';
	return 0;
}