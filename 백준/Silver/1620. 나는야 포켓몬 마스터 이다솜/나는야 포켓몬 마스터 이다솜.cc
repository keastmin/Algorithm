#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	unordered_map<string, int> um1;
	unordered_map<int, string> um2;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string pkm;
		cin >> pkm;
		um1.insert({ pkm, i });
		um2.insert({ i, pkm });
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			cout << um2[stoi(str)] << '\n';
		}
		else {
			cout << um1[str] << '\n';
		}
	}

	return 0;
}