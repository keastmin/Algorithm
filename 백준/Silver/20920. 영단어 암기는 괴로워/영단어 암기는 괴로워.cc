#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(vector<string>& a, vector<string>& b) {
	if (stoi(a[1]) == stoi(b[1])) {
		if (a[0].size() == b[0].size())
			return a[0] < b[0];
		else
			return a[0].size() > b[0].size();
	}

	return stoi(a[1]) > stoi(b[1]);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<string>> words(N + 1, vector<string>(2));
	unordered_map<string, int> um;
	int index = 1;

	for (int i = 0; i < N; i++) {
		string w;
		cin >> w;

		if (w.size() >= M) {
			if (um[w] == 0) {
				um[w] = index++;
				words[um[w]][0] = w;
				words[um[w]][1] = "1";
			}
			else {
				words[um[w]][1] = to_string(stoi(words[um[w]][1]) + 1);
			}
		}
	}
	sort(words.begin() + 1, words.begin() + index, cmp);

	for (int i = 1; i < index; i++) {
		cout << words[i][0] << '\n';
	}


	return 0;
}