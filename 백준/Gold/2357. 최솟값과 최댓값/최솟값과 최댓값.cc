#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<vector<int>> tree;

void build(int node, int start, int end) {
	if (start == end) {
		tree[node][0] = arr[start];
		tree[node][1] = arr[start];
	}
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node][0] = min(tree[node << 1][0], tree[node << 1 | 1][0]);
		tree[node][1] = max(tree[node << 1][1], tree[node << 1 | 1][1]);
	}
}

vector<int> query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return { 1000000001, 0 };
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	vector<int> a = query(node << 1, start, mid, left, right);
	vector<int> b = query(node << 1 | 1, mid + 1, end, left, right);
	int minAB = min(a[0], b[0]);
	int maxAB = max(a[1], b[1]);
	return { minAB, maxAB };
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	arr.resize(N);
	tree.resize(N * 4, vector<int>(2));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	build(1, 0, N - 1);
	vector<int> res(2);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		res = query(1, 0, N - 1, a - 1, b - 1);
		cout << res[0] << ' ' << res[1] << '\n';
	}

	return 0;
}