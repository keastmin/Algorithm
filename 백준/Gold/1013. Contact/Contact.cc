#include <iostream>
#include <string>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char n[201];
		int index = 0;
		bool yesno = true;
		cin >> n;

		while (n[index]) {
			if (n[index] == '0') {
				index++;
				if (n[index] == '1') {
					index++;
				}
				else {
					yesno = false;
					break;
				}
			}

			if (n[index] == '1') {
				int zeroCount = 0;
				int oneCount = 0;
				index++;
				if (n[index] == '1' || n[index + 1] == '1' || n[index] == NULL) {
					yesno = false;
					break;
				}
				else {
					while (n[index] == '0') {
						index++;
						zeroCount++;
					}
					if (zeroCount < 2 || n[index] != '1') {
						yesno = false;
						break;
					}
				}

				while (n[index] == '1') {
					index++;
					oneCount++;
				}

				if (oneCount == 1) {
					if (n[index] == NULL) {
						break;
					}
					else if (n[index] == '0' && n[index + 1] == '0') {
						yesno = false;
						break;
					}
					else if(n[index] == '0' && n[index + 1] == NULL) {
						yesno = false;
						break;
					}
				}
				else if (oneCount > 1) {
					if (n[index] == NULL) {
						break;
					}
					else if (n[index] == '0' && n[index + 1] == '0') {
						index--;
					}
					else if (n[index] == '0' && n[index + 1] == NULL) {
						yesno = false;
						break;
					}
				}

			}
		}

		if (yesno)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}