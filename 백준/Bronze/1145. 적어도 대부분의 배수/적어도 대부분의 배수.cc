#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> n(5);
	cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];

	int t = 3;
	int check = 0;
	while (check < 3) {
		check = 0;
		t++;
		
		for (int i = 0; i < 5; i++) {
			if (t % n[i] == 0) check++;
		}
	}

	cout << t << '\n';

	return 0;
}