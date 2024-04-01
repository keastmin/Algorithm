#include<iostream>
#include<string>
using namespace std;

int main() {
	string word;

	int N;

	int group_word = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		char corr[100] = { NULL };
		bool same_sp = false;
		int count = 0;

		cin >> word;

		for (int j = 0; j < word.length(); j++) {
			if(word[j] != word[j+1])
				corr[count++] = word[j];
		}
		
		for (int j = 0; j < count; j++) {
			for (int k = j + 1; k < count; k++) {
				if (corr[j] == corr[k]) {
					same_sp = true;
				}
			}
		}

		if (!same_sp)
			group_word++;
	}

	cout << group_word << '\n';

	return 0;
}