#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	vector<int> res(N + 1);
	res[0] = 0;
	int tmp = arr[1];

	for (int i = 1; i <= N; i++) {		
		res[i] = max(res[i - 1] + arr[i], arr[i]);
		tmp = max(res[i], tmp);
	}
	cout << tmp << '\n';

	return 0;
}