#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);	

	unordered_map<string, bool> dUm;
	unordered_map<string, bool> bUm;
	vector<string> arr;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		dUm.insert({ name, true });
	}

	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		bUm.insert({ name, true });
	}

	if (dUm.size() < bUm.size()) {
		for (const auto d : dUm) {
			if (bUm[d.first] == true) {
				arr.push_back(d.first);
			}
		}
	}
	else {
		for (const auto b : bUm) {
			if (dUm[b.first] == true) {
				arr.push_back(b.first);
			}
		}
	}
	sort(arr.begin(), arr.end());

	cout << arr.size() << '\n';
	for (const auto a : arr) {
		cout << a << '\n';
	}
	

	return 0;
}