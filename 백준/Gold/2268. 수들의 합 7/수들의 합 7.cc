/**********************************************************
2024-02-11
https://github.com/keastmin
백준/2268/수들의 합 7
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> tree;

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return query(node << 1, start, mid, left, right) +
		   query(node << 1 | 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll val) {
	if (start == end) {
		tree[node] = val;
	}
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid) {
			update(node << 1, start, mid, index, val);
		}
		else {
			update(node << 1 | 1, mid + 1, end, index, val);
		}
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	tree.resize(N * 4, 0);

	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int qa, qb;
			cin >> qa >> qb;
			int mi = (qa > qb) ? qb : qa;
			int ma = (qa > qb) ? qa : qb;
			cout << query(1, 0, N - 1, mi - 1, ma - 1) << '\n';
		}
		else if (t == 1) {
			int idx;
			ll val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx - 1, val);
		}
	}

	return 0;
}