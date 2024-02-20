/**********************************************************
2024-02-20
https://github.com/keastmin
백준/6213/Balanced Lineup
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<ll>> arr;
vector<vector<ll>> tree;

void build(int node, int start, int end) {
	if (start == end) tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node][0] = max(tree[node << 1][0], tree[node << 1 | 1][0]);
		tree[node][1] = min(tree[node << 1][1], tree[node << 1 | 1][1]);
	}
}

vector<ll> query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return { 0, 9223372036854775800 };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	vector<ll> a = query(node << 1, start, mid, left, right);
	vector<ll> b = query(node << 1 | 1, mid + 1, end, left, right);
	ll ma = (a[0] < b[0]) ? b[0] : a[0];
	ll mi = (a[1] < b[1]) ? a[1] : b[1];
	return { ma, mi };
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	arr.resize(N, vector<ll>(2));
	tree.resize(N * 4, vector<ll>(2));
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		arr[i][0] = t;
		arr[i][1] = t;
	}

	build(1, 0, N - 1);

	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;

		vector<ll> res = query(1, 0, N - 1, x - 1, y - 1);
		cout << res[0] - res[1] << '\n';
	}

	return 0;
}