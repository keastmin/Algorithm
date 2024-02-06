/**********************************************************
2024-02-06
https://github.com/keastmin
백준/25069/붙임성 좋은 총총이
난이도: 실버4
유형: 문자열, 해쉬(Hash)
**********************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	unordered_map<string, bool> um;
	um.insert({ "ChongChong", true });
	int count = 1;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string n1, n2;
		cin >> n1 >> n2;

		if ((um[n1] == false && um[n2] == true) || (um[n2] == false && um[n1] == true)) {
			count++;
			um[n1] = true;
			um[n2] = true;
		}
	}

	cout << count << '\n';

	return 0;
}