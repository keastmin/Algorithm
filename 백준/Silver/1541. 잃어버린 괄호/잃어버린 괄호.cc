#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	string calc;
	cin >> calc;

	int sum = 0;
	bool minus = false;
	string tmp = "";
	for (int i = 0; i < calc.size(); i++) {
		if (calc[i] >= '0' && calc[i] <= '9') tmp += calc[i];
		else {
			if (calc[i] == '-' && !minus) {
				sum += stoi(tmp);
				tmp = "";
				minus = true;
				continue;
			}
			if (!minus) sum += stoi(tmp);
			else sum -= stoi(tmp);
			tmp = "";
		}
	}

	if (!minus) sum += stoi(tmp);
	else sum -= stoi(tmp);

	cout << sum << '\n';

	return 0;
}