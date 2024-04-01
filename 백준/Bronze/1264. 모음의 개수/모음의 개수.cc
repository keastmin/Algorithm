#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		int count = 0;
		string str;
		getline(cin, str);
		if (!str.compare("#")) {
			break;
		}

		for (auto& s : str) {
			if (s >= 'A' && s <= 'Z') s = tolower(s);
			if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
				count++;
		}
		cout << count << '\n';
	}

	return 0;
}