#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		int absA = abs(a); int absB = abs(b);
		if (absA == absB) return a > b;
		return absA > absB;
	}
};

int N;
priority_queue<int, vector<int>, compare> pq;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int macro;
		cin >> macro;

		if (macro != 0) pq.push(macro);
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}