#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] > b[1];
}

int avg(double s) {
	if (s - (int)s >= 0.5) {
		return (int)s + 1;
	}
	else if (s - (int)s <= -0.5) {
		return (int)s - 1;
	}

	return (int)s;
}

int mid(vector<vector<int>> v, int n, int& r) {
	sort(v.begin(), v.end());
	r = v[v.size() - 1][0] - v[0][0];
	return v[n / 2][0];
}

int many(vector<vector<int>> v) {
	sort(v.begin(), v.end(), cmp);

	if (v.size() > 1 && v[0][1] == v[1][1]) {
		return v[1][0];
	}
	return v[0][0];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int min = INT_MAX;
	int max = INT_MIN;
	double sum = 0;
	int N;
	cin >> N;

	unordered_map<int, int> um;
	vector<vector<int>> arr(N, { 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0];

		um[arr[i][0]]++;
		arr[i][1] = um[arr[i][0]];

		sum += ((double)arr[i][0] / N);
	}

	int range = 0;
	cout << avg(sum) << '\n';
	cout << mid(arr, N, range) << '\n';
	cout << many(arr) << '\n';
	cout << range << '\n';

	return 0;
}