#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string alhCr[20000];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> alhCr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (alhCr[i].size() > alhCr[j].size()) {
				string tmp_str;
				tmp_str = alhCr[i];
				alhCr[i] = alhCr[j];
				alhCr[j] = tmp_str;
			}
		}
	}

	//sort(alhCr, alhCr + N);

	int count = 0;
	int pre_count = 0;
	while (1) {
		if (alhCr[count].size() == alhCr[pre_count].size()) {
			count++;
		}
		else{
			sort(alhCr + pre_count, alhCr + count);
			pre_count = count;
			if (!alhCr[count].size())
				break;
		}
	}

	for (int i = 0; i < N; i++) {
		if (i == 0)
			cout << alhCr[i] << '\n';
		else
			if (alhCr[i - 1] != alhCr[i])
				cout << alhCr[i] << '\n';
		
	}


	return 0;
}