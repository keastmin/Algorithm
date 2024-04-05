#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		cout << (int)(str[0] - '0') + (int)(str[2] - '0') << '\n';
	}

	return 0;
}