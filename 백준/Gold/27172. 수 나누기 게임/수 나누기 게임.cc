#include <iostream>
#include <vector>
using namespace std;

vector<int> cards;
vector<int> score(1000001, 0);
vector<bool> have(1000001, false);

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cards.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
		have[cards[i]] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = cards[i] * 2; j <= 1000000; j += cards[i]) {
			if (have[j]) {
				score[cards[i]]++;
				score[j]--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << score[cards[i]] << ' ';
	}
	return 0;
}