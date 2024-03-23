#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str;
int N;

int stre(int i) {
	char tmp = str[i];
	while (i < N) {
		if (str[i] != tmp) {
			break;
		}
		i++;
	}

	return i;
}

int main() {
	cin >> str;
	N = str.size();

	int res[2] = { 0, 0 };

	int idx = 0;
	while (idx < N) {
		if (str[idx] == '0') {
			res[0]++;
		}
		else {
			res[1]++;
		}

		idx = stre(idx);
	}

	cout << min(res[0], res[1]) << '\n';

	return 0;
}