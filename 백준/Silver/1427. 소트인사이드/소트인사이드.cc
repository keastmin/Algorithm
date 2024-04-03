#include<iostream>
#include<algorithm>
using namespace std;

int desc(int a, int b) {
	return a > b;
}

int main() {
	string N;
	cin >> N;
	sort(N.begin(), N.end(), desc);

	cout << N;

	return 0;
}