#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> arr;
vector<int> len;
vector<int> indexNum(26, 0);

int main() {
	cin >> N;
	arr.resize(N);
	len.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		len[i] = arr[i].size();
	}

	for (int i = 0; i < N; i++) {
		int cal = 1;
		for (int j = len[i] - 1; j >= 0; j--) {
			indexNum[arr[i][j] - 'A'] += cal;
			cal *= 10;
		}
	}

	sort(indexNum.begin(), indexNum.end(), greater<>());

	//cout << '\n';
	//for (const auto i : indexNum) {
	//	cout << i << ' ';
	//}
	//cout << '\n';

	int res = 0;
	for (int i = 0; i < 10; i++) {
		res += indexNum[i] * (9 - i);
	}

	cout << res << '\n';

	return 0;
}