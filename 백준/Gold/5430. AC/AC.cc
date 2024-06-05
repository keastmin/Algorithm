#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void InputArray(vector<int>& arr, string x) {
	istringstream ss(x);
	string tmp;
	int idx = 0;

	while (getline(ss, tmp, ',')) {
		arr[idx++] = stoi(tmp);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T, n;
	string p, x;
	
	cin >> T;
	while (T--) {
		cin >> p >> n >> x;

		vector<int> arr(n);
		x.erase(0, 1);
		x.erase(x.length() - 1, 1);
		
		InputArray(arr, x);

		int s = 0;
		int e = arr.size();
		bool rev = false;

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') rev = !rev;
			else {
				if (!rev) s++;
				else e--;
			}
		}

		if (s > e) cout << "error" << '\n';
		else {
			cout << "[";
			if (!rev) {
				for (int i = s; i < e; i++) {
					if (i > s) cout << ",";
					cout << arr[i];
				}
			}
			else {
				for (int i = e - 1; i >= s; i--) {
					if (i < e - 1) cout << ",";
					cout << arr[i];
				}
			}
			cout << "]" << '\n';
		}

		//cout << arr.size() << '\n';
		//for (const auto& a : arr) {
		//	cout << a << ' ';
		//}
		//cout << '\n';
	}

	return 0;
}