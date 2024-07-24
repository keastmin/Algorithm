#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<pair<int, int>>> vvpii;

int M, N;
vvpii arr;
int res = 0;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void Input() {
	cin >> M >> N;
	arr.resize(M, vector<pair<int, int>>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j].first;
			arr[i][j].second = j;
		}
		sort(arr[i].begin(), arr[i].end(), cmp);
	}
}

bool Check(int idx1, int idx2) {
	if (arr[idx1][0].second != arr[idx2][0].second) return false;

	int prev1 = arr[idx1][0].first;
	int prev2 = arr[idx2][0].first;

	for (int i = 1; i < N; i++) {
		if (arr[idx1][i].second != arr[idx2][i].second) return false;

		if (prev1 == arr[idx1][i].first) {
			if (prev2 != arr[idx2][i].first) {
				return false;
			}
		}

		if (prev2 == arr[idx2][i].first) {
			if (prev1 != arr[idx1][i].first) {
				return false;
			}
		}

		prev1 = arr[idx1][i].first;
		prev2 = arr[idx2][i].first;
	}

	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();

	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			if (Check(i, j)) res++;
		}
	}

	cout << res << '\n';
	//for (const auto& ar : arr) {
	//	for (const auto& a : ar) {
	//		cout << a.first << ' ' << a.second << ", ";
	//	}
	//	cout << '\n';
	//}

	return 0;
}