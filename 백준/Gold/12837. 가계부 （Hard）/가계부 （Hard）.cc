/**********************************************************
2024-02-20
https://github.com/keastmin
백준/12837/가계부 (Hard)
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> tree;

ll query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	ll a = query(node << 1, start, mid, left, right);
	ll b = query(node << 1 | 1, mid + 1, end, left, right);
	return a + b;
}

void update(int node, int start, int end, int index, ll val) {
	if (start == end) {
		tree[node] += val;
	}
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid)
			update(node << 1, start, mid, index, val);
		else
			update(node << 1 | 1, mid + 1, end, index, val);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	arr.resize(N, 0);
	tree.resize(N * 4, 0);

	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int p;
			ll x;
			cin >> p >> x;
			update(1, 0, N - 1, p - 1, x);
		}
		else if (a == 2) {
			int p, q;
			cin >> p >> q;
			cout << query(1, 0, N - 1, p - 1, q - 1) << '\n';
		}
	}

	return 0;
}