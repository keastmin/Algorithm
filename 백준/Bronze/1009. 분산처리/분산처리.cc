#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp1, tmp2;
		int aga = 0;
		cin >> tmp1 >> tmp2;
		
		tmp1 = tmp1 % 10;
		aga = tmp1;
		for (int j = 0; j < tmp2 - 1; j++) {
			tmp1 *= aga;
			if (tmp1 > 10) {
				tmp1 = tmp1 % 10;
			}
		}
		if (tmp1 > 10)
			tmp1 = tmp1 % 10;
		if (tmp1 == 0)
			tmp1 = 10;
		cout << tmp1 << endl;
	}
	
	return 0;
}