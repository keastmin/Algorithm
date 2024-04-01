#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	vector<int> arr({ 0, 0, w, h });
	int min = INT_MAX;
	for (int i = 0; i < 4; i++) {
		int t = (i % 2) ? y : x;
		t -= arr[i];
		t = (t < 0) ? (-1) * t : t;
		
		if (min > t) {
			min = t;
		}
	}

	cout << min << '\n';

	return 0;
}