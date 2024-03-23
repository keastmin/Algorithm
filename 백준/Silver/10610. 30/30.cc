#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string N;
	cin >> N;

	// 모든 자릿수의 합 계산
	long long sum = 0;
	for (char digit : N) {
		sum += digit - '0';
	}

	// 3의 배수 판정법과 0의 존재 여부 확인
	if (sum % 3 != 0 || N.find('0') == string::npos) {
		cout << -1;
	}
	else {
		// 조건을 만족하면 내림차순으로 정렬
		sort(N.rbegin(), N.rend());
		cout << N;
	}

	return 0;
}