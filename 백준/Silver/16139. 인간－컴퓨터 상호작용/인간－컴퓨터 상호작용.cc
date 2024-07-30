#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> alp;
int q;
string str;

void Input() {
	cin >> str;
	alp.resize(str.length(), vector<int>(26, 0));
	int tmp = str[0] - 'a';
	alp[0][tmp]++;
	for (int i = 1; i < str.length(); i++) {
		for (int j = 0; j < 26; j++) {
			alp[i][j] = alp[i - 1][j];
		}
		tmp = str[i] - 'a';
		alp[i][tmp]++;
	}
	cin >> q;
}

void Question() {
	char a;
	int l, r;
	
	for (int i = 0; i < q; i++) {
		cin >> a >> l >> r;
		int tmp = a - 'a';

		if (l == 0) {
			cout << alp[r][tmp] << '\n';
		}
		else {
			cout << alp[r][tmp] - alp[l - 1][tmp] << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Question();

	return 0;
}