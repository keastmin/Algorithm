#include<iostream>
#include <vector>
using namespace std;

int N, K, R;
vector<int> tree[51];
int res = 0;

int dfs(int node) {
	if (node == K) return -1;
	if (tree[node].size() == 0) {
		res++;
		return 0;
	}

	for (const auto t : tree[node]) {
		int tmp = dfs(t);
		if (tmp == -1 && tree[node].size() == 1)
			res++;
	}

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p == -1) R = i;
		else tree[p].push_back(i);
	}
	cin >> K;

	dfs(R);
	cout << res << '\n';

	return 0;
}