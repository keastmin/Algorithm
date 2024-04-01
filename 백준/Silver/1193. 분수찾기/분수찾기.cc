#include<iostream>
#include<string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 1;
	int sum = 0;
	string result;
	while (sum < N) {
		sum += count++;
	}
	count -= 1;

	if (count % 2 == 0) {
		cout << 1 + ((count - 1) - (sum - N)) << "/" << count - ((count - 1) - (sum - N)) << '\n';	
	}
	else {
		cout << count - ((count - 1) - (sum - N)) << "/" << 1 + ((count - 1) - (sum - N)) << '\n';
	}

	return 0;
}