#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(9);
vector<int> res(7);

int FindShortMan(int f, int s) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (i != f && i != s) {
			sum += arr[i];
		}
	}
	return sum;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	bool check = false;
	vector<int> idxs(2);
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int sum = FindShortMan(i, j);
			if (sum == 100) {
				idxs[0] = i;
				idxs[1] = j;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	int idx = 0;
	for (int i = 0; i < 9; i++) {
		if (i == idxs[0] || i == idxs[1]) continue;
		res[idx++] = arr[i];
	}

	sort(res.begin(), res.end());

	for (const auto r : res) {
		cout << r << '\n';
	}

	return 0;
}