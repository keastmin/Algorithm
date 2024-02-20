/**********************************************************
2024-02-20
https://github.com/keastmin
백준/18436/수열과 쿼리 37
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> tree;

void build(int node, int start, int end) {
	if (start == end) tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node][0] = tree[node << 1][0] + tree[node << 1 | 1][0];
		tree[node][1] = tree[node << 1][1] + tree[node << 1 | 1][1];
	}
}

int query(int node, int start, int end, int left, int right, int m) {
	if (left > end || start > right) return 0;
	if (left <= start && end <= right) {
		if (m == 3) return tree[node][0];
		return tree[node][1];
	}

	int mid = (start + end) >> 1;
	int a = query(node << 1, start, mid, left, right, m);
	int b = query(node << 1 | 1, mid + 1, end, left, right, m);
	return a + b;
}

void update(int node, int start, int end, int index, vector<int> val) {
	if (start == end) tree[node] = val;
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid)
			update(node << 1, start, mid, index, val);
		else
			update(node << 1 | 1, mid + 1, end, index, val);
		tree[node][0] = tree[node << 1][0] + tree[node << 1 | 1][0];
		tree[node][1] = tree[node << 1][1] + tree[node << 1 | 1][1];
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N;

	arr.resize(N, vector<int>(2, 0));
	tree.resize(N * 4, vector<int>(2, 0));

	int t, x, y;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t % 2 != 0) arr[i][0] = 1;
		else arr[i][1] = 1;
	}

	build(1, 0, N - 1);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> t >> x >> y;

		if (t == 1) {
			vector<int> r(2, 0);
			if (y % 2 != 0) r[0] = 1;
			else			r[1] = 1;
			update(1, 0, N - 1, x - 1, r);
		}
		else {
			cout << query(1, 0, N - 1, x - 1, y - 1, t) << '\n';
		}
	}
	return 0;
}