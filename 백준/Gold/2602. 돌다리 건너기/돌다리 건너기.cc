#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

vvvi dp;
string str, bridge[2];
int res = 0;

int FindPath(int currIdx, int currBridge, int strIdx) {
	if (strIdx == str.size()) return 1;
	if (currIdx == bridge[0].size()) return 0;

	int& ret = dp[currIdx][currBridge][strIdx];
	if (ret != -1) return ret;

	ret = 0;

	int nextBridge = (currBridge == 0);
	for (int i = currIdx; i < bridge[0].size(); i++) {
		if (bridge[currBridge][i] == str[strIdx]) {
			ret += FindPath(i + 1, nextBridge, strIdx + 1);
		}
	}

	return ret;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> str >> bridge[0] >> bridge[1];
	int f = bridge[0].size(), s = 2, t = str.size();
	dp.resize(f, vvi(s, vi(t, -1)));

	res += FindPath(0, 0, 0);
	res += FindPath(0, 1, 0);

	cout << res << '\n';

	return 0;
}