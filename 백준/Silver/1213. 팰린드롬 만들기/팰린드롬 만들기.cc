#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

int main() {
	int alpCount[26];
	memset(alpCount, 0, 26 * sizeof(int));

	string str;
	cin >> str;

	string res = "";
	string resRev = "";

	for (const auto& s : str) {
		alpCount[(int)s - 'A']++;
	}

	//for (const auto& a : alpCount) {
	//	cout << a << ' ';
	//}


	for (int i = 0; i < 26; i++) {
		char tmp = 'A' + i;
		while (alpCount[i] >= 2) {
			res += tmp;
			resRev = tmp + resRev;
			alpCount[i] -= 2;
		}
	}

	int middleCnt = 0;
	for (int i = 0; i < 26; i++) {
		char tmp = 'A' + i;
		if (alpCount[i] == 1) {
			res += tmp;
			middleCnt++;
		}
	}

	if (middleCnt > 1) {
		cout << "I'm Sorry Hansoo" << '\n';
	}
	else {
		cout << res + resRev << '\n';
	}

	return 0;
}