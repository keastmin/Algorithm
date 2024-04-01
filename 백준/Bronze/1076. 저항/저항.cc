#include <iostream>
#include <string>
using namespace std;

int colorValue(string c) {
	int res = 0;
	if (c.compare("black") == 0) {
		res = 0;
	}
	else if (c.compare("brown") == 0) {
		res = 1;
	}
	else if (c.compare("red") == 0) {
		res = 2;
	}
	else if (c.compare("orange") == 0) {
		res = 3;
	}
	else if (c.compare("yellow") == 0) {
		res = 4;
	}
	else if (c.compare("green") == 0) {
		res = 5;
	}
	else if (c.compare("blue") == 0) {
		res = 6;
	}
	else if (c.compare("violet") == 0) {
		res = 7;
	}
	else if (c.compare("grey") == 0) {
		res = 8;
	}
	else if (c.compare("white") == 0) {
		res = 9;
	}

	return res;
}

void colorMul(int value, string c) {
	if (value > 0) {
		if (c.compare("brown") == 0) {
			cout << "0";
		}
		else if (c.compare("red") == 0) {
			cout << "00";
		}
		else if (c.compare("orange") == 0) {
			cout << "000";
		}
		else if (c.compare("yellow") == 0) {
			cout << "0000";
		}
		else if (c.compare("green") == 0) {
			cout << "00000";
		}
		else if (c.compare("blue") == 0) {
			cout << "000000";
		}
		else if (c.compare("violet") == 0) {
			cout << "0000000";
		}
		else if (c.compare("grey") == 0) {
			cout << "00000000";
		}
		else if (c.compare("white") == 0) {
			cout << "000000000";
		}
	}
}

int main() {
	string color1;
	string color2;
	string color3;
	int value;

	cin >> color1;
	cin >> color2;
	cin >> color3;

	value = colorValue(color1) * 10 + colorValue(color2);

	cout << value;
	colorMul(value, color3);
	cout << '\n';
	
	return 0;
}