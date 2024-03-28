#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < N; i++) {
		int grade = 1;
		int cX = arr[i].first;
		int cY = arr[i].second;

		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (cX < arr[j].first && cY < arr[j].second) {
					grade++;
				}
			}
		}

		cout << grade << ' ';
	}

	return 0;
}