#include <iostream>
#include <vector>
using namespace std;

struct Egg {
	int S, W;
};

int N;
vector<Egg> eggs;
int res = 0;

void backTracking(int curr) {
	if (curr > N) return;

	for (int i = 0; i < N; i++) {
		if (eggs[curr].S <= 0) backTracking(curr + 1);
		else if (curr == i || eggs[i].S <= 0) continue;
		else {
			eggs[curr].S -= eggs[i].W;
			eggs[i].S -= eggs[curr].W;

			backTracking(curr + 1);

			eggs[curr].S += eggs[i].W;
			eggs[i].S += eggs[curr].W;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (eggs[i].S <= 0) cnt++;
	}

	res = max(res, cnt);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	eggs.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> eggs[i].S >> eggs[i].W;
	}

	backTracking(0);

	cout << res << '\n';

	return 0;
}