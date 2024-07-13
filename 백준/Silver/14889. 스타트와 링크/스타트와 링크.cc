#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int res = 1000000;
int N;
int team;
int allPower = 0;
vector<vector<int>> power;
vector<int> teams;
vector<int> otherTeams;

bool OtherTeamsCheck(int num) {
	for (const auto t : teams) {
		if (num == t) return true;
	}
	return false;
}

void FindMinScoreDiff(int selec, int cur) {
	if (selec == team) {
		int sum = 0;
		int otherSum = 0;

		for (const auto tt : teams) {
			for (const auto t : teams) {
				sum += power[tt][t];
			}
		}

		int idx = 0;
		for (int i = 0; i < N; i++) {
			if (!OtherTeamsCheck(i)) {
				otherTeams[idx] = i;
				idx++;
			}
		}

		for (const auto tt : otherTeams) {
			for (const auto t : otherTeams) {
				otherSum += power[tt][t];
			}
		}

		int diff = abs(otherSum - sum);
		res = min(res, diff);

		return;
	}

	for (int i = cur + 1; i < N; i++) {
		if ((team - selec) + i <= N) {
			teams[selec] = i;
			FindMinScoreDiff(selec + 1, i);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	team = N / 2;
	power.resize(N, vector<int>(N, 0));
	teams.resize(N / 2, -1);
	otherTeams.resize(N / 2, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power[i][j];
			allPower += power[i][j];
		}
	}

	for (int i = 0; i <= N / 2; i++) {
		teams[0] = i;
		FindMinScoreDiff(1, i);
	}

	cout << res << '\n';

	return 0;
}