#include<iostream>
#include<string>
using namespace std;

int main() {
	string word;
	int alp_count[26] = { 0 };
	int max = 0;
	int max_word;
	bool result = true;
	char result_word;
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if ((word[i] == j + 'A') || (word[i] == j + 'a')) {
				alp_count[j]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max < alp_count[i]) {
			max = alp_count[i];
			max_word = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if ((i != max_word) && (alp_count[i] == alp_count[max_word]))
			result = false;
	}
	result ? result_word = 'A' + max_word : result_word = '?';

	cout << result_word << '\n';

	return 0;
}