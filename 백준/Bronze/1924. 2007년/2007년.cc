#include <iostream>
#include <vector>
#include <string>
using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string week[7] = { "SUN", "MON", "TUE", "WED", "THU","FRI", "SAT"};
int x, y;

int main() {
	cin >> x >> y;

	int sum = 0;
	for (int i = 1; i < x; i++) {
		sum += month[i - 1];
	}
	sum += y;

	cout << week[sum % 7] << '\n';

	return 0;
}