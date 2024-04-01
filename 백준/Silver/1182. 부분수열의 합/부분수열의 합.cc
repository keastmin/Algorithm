#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int search(int index, int sum, int end, int target) {
	if (index == end) {
		if (sum == target) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int notInclude = search(index + 1, sum, end, target);
	int include = search(index + 1, sum + arr[index], end, target);

	return notInclude + include;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int minus = (S == 0) ? 1 : 0;
	cout << search(0, 0, N, S) - minus << '\n';

	return 0;
}