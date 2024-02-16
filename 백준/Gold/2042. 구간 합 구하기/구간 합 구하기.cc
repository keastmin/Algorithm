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
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return query(node << 1, start, mid, left, right) +
		query(node << 1 | 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll val) {
	if (start == end) {
		arr[index] = val;
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

	int N, M, K;
	cin >> N >> M >> K;
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	build(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int mode;
		cin >> mode;
		if (mode == 1) {
			int idx;
			ll val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx - 1, val);
		}
		else if (mode == 2) {
			int qa, qb;
			cin >> qa >> qb;
			ll res = query(1, 0, N - 1, qa - 1, qb - 1);
			cout << res << '\n';
		}
	}

	return 0;
}