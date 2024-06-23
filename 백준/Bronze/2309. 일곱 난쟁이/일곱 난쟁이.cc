#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PEO 9

vector<int> arr(9);
int sum = 0;

int main() {

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < PEO - 1; i++) {
		for (int j = i + 1; j < PEO; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				for (int k = 0; k < PEO; k++) {
					if (k != i && k != j) {
						cout << arr[k] << '\n';
					}
				}
				return 0;
			}
		}
	}

	return 0;
}