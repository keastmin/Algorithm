#include<iostream>
#include <math.h>
using namespace std;

int main() {
	int tk = 0;
	int count = 0;
	cin >> tk;
	for (int i = 0; i < tk; i++) {
		int x, y;
		cin >> x >> y;

		int length = y - x;	
		int d = (int)sqrt(length);
		count = d + (d - 1);

		if (d * d < length && d * (d + 1) >= length)
			count += 1;
		else if (d * (d + 1) < length)
			count += 2;		

		cout << count << endl;
	}

	return 0;
}