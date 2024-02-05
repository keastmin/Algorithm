#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double dis1 = abs(r1 - r2);
		double dis2 = r1 + r2;
		
		if (d == 0) {
			if (r1 == r2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			if (d == dis2 || d == dis1) {
				cout << 1 << '\n';
			}
			else if (d < dis2 && d > dis1) {
				cout << 2 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}