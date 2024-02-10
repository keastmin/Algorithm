/**********************************************************
2024-02-11
https://github.com/keastmin
백준/11505/구간 곱 구하기
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ll;

#define MOD 1000000007

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
		tree[node] = tree[node << 1] * tree[node << 1 | 1];
		tree[node] = tree[node] % MOD;
	}
}

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) >> 1;
	return (query(node << 1, start, mid, left, right) *
			query(node << 1 | 1, mid + 1, end, left, right)) % MOD;
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
		tree[node] = tree[node << 1] * tree[node << 1 | 1];
		tree[node] = tree[node] % MOD;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
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
		int t;
		cin >> t;
		if (t == 1) {
			int idx;
			ll val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx - 1, val);
		}
		else if (t == 2) {
			int qa, qb;
			cin >> qa >> qb;
			cout << query(1, 0, N - 1, qa - 1, qb - 1) << '\n';
		}
	}

	return 0;
}