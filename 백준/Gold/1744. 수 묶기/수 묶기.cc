#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
vector<int> arrZ;
vector<int> arrM;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a > 0)			arr.push_back(a);
		else if (a == 0)	arrZ.push_back(a);
		else				arrM.push_back(a);
	}

	sort(arr.begin(), arr.end(), greater<>());
	sort(arrM.begin(), arrM.end());

	int res = 0;

	int idx;
	for (idx = 0; idx < arr.size(); idx += 2) {
		int left = arr.size() - idx;

		if (left < 2) break;
		if (arr[idx] == 1 || arr[idx + 1] == 1) break;

		res += (arr[idx] * arr[idx + 1]);
	}
	for (idx; idx < arr.size(); idx++) {
		res += arr[idx];
	}


	for (idx = 0; idx < arrM.size(); idx += 2) {
		int left = arrM.size() - idx;

		if (left < 2) break;

		res += (arrM[idx] * arrM[idx + 1]);
	}

	if (arrM.size() - idx == 1 && arrZ.size() == 0) {
		res += arrM[idx];
	}

	cout << res << '\n';

	return 0;
}