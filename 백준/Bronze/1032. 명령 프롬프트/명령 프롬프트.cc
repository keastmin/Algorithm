#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	char text[51];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx = 0;
		if (i == 0)
			cin >> text;
		else {
			char tmp[51];
			cin >> tmp;
			while (text[idx]) {
				if (text[idx] != tmp[idx])
					text[idx] = '?';
				idx++;
			}
		}
	}
	
	cout << text << endl;

	return 0;
}