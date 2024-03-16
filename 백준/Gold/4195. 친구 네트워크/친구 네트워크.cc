#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, int> umsi;

int T, N;

int find(int x, vector<int>& p) {
	if (x == p[x]) return x;
	return p[x] = find(p[x], p);
}

void unionSet(int x1, int x2, vector<int>& p, vector<int>& net) {
	x1 = find(x1, p);
	x2 = find(x2, p);
	if (x1 != x2) {
		p[x2] = x1;
		net[x1] += net[x2];
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N;

		umsi ntoi;
		int index = 0;	
		vector<int> parents(2 * N), networkSize(2 * N, 1);
		for (int i = 0; i < 2 * N; i++) parents[i] = i;
		for (int i = 0; i < N; i++) {
			string n1, n2;
			cin >> n1 >> n2;

			if (ntoi.count(n1) == 0) ntoi[n1] = index++;
			if (ntoi.count(n2) == 0) ntoi[n2] = index++;

			unionSet(ntoi[n1], ntoi[n2], parents, networkSize);
			cout << networkSize[find(ntoi[n1], parents)] << '\n';
		}
	}

	return 0;
}