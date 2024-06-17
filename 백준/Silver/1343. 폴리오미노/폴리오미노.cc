#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string board;
	cin >> board;

	int cnt = 0;
	for (int i = 0; i < board.length(); i++) {
		if (board[i] == 'X') {
			cnt++;
		}
		
		if (cnt == 4) {
			while (cnt > 0) {
				cnt--;
				board[i - cnt] = 'A';
			}
		}
		else if (board[i] == '.') {
			if (cnt == 3 || cnt == 1) {
				cout << -1 << '\n';
				return 0;
			}
			else if(cnt == 2) {
				int idx = i - 1;
				while (cnt > 0) {
					cnt--;
					board[idx - cnt] = 'B';
				}
			}
		}
	}
	if (cnt == 3 || cnt == 1) {
		cout << -1 << '\n';
		return 0;
	}
	else if (cnt == 2) {
		for (int i = board.length() - 2; i < board.length(); i++) {
			board[i] = 'B';
		}
	}
	else if (cnt == 4) {
		for (int i = board.length() - 4; i < board.length(); i++) {
			board[i] = 'A';
		}
	}

	cout << board << '\n';

	return 0;
}