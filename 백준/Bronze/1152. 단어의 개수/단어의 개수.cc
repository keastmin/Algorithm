#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	int count = 0;
	bool word_b = false;
	getline(cin, str);

	for (int i = 0; i < str.length();i++) {
		if (str[i] != ' ') {
			if (word_b == false)
				count++;
			word_b = true;
		}
		else {
			word_b = false;
		}
	}

	cout << count;

	return 0;
}