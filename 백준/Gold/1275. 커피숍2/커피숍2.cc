#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> tree;

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
	}
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
}

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

	int N, Q;
	cin >> N >> Q;
	arr.resize(N);
	tree.resize(N * 4);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	build(1, 0, N - 1);

	int x, y, a;
	ll b;
	int sx, ry;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		sx = (x < y) ? (x - 1) : (y - 1);
		ry = (x < y) ? (y - 1) : (x - 1);
		cout << query(1, 0, N - 1, sx, ry) << '\n';
		update(1, 0, N - 1, a - 1, b);
	}

	return 0;
}