#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
string dp[10001];

string Plus(string A, string B) {
	string res = "";

	int up = 0;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	while (A.length() < B.length()) A += "0";
	while (A.length() > B.length()) B += "0";

	for(int i = 0; i < A.length(); i++) {
		int sum = (A[i] - '0' + B[i] - '0' + up);
		res += to_string(sum % 10);
		up = sum / 10;
	}
	if (up == 1) {
		res += "1";
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	int N;
	dp[0] = '0';
	dp[1] = '1';

	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = Plus(dp[i - 1], dp[i - 2]);
	}

	cout << dp[N] << '\n';

	return 0;
}