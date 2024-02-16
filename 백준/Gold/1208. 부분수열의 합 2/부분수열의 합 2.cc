#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> arr;

long long res;
unordered_map<int, int> subsum;

int N, S;

void MeetMid(int start, int end, int sum) {
	//cout << start << ' ' << end << ' ' << sum << '\n';
	if (start == end) {
		if (end == N) res += subsum[S - sum];
		else subsum[sum]++;
		return;
	}
	MeetMid(start + 1, end, sum + arr[start]);
	MeetMid(start + 1, end, sum);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	MeetMid(0, N / 2, 0);
	MeetMid(N / 2, N, 0);

	res += S == 0 ? -1 : 0;
	cout << res << '\n';
	return 0;
}