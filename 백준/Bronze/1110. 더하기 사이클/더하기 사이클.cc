#include<iostream>
using namespace std;

int main() {
	int n = 0, otn = 0;
	int count = 0;

	cin >> n;
	otn = n;
	do {
		n = (n % 10 * 10) + ((n / 10 + n % 10) % 10);
		count++;
	} while (n != otn);
	
	cout << count << '\n';

	return 0;
}