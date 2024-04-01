#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int max = 0;
	int min = 1000000;

	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}

	cout << min * max << endl;

	return 0;
}