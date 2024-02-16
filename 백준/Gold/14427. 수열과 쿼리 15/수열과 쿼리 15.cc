/**********************************************************
2024-02-17
https://github.com/keastmin
백준/14427/수열과 쿼리 15
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int>> tree;

void build(int node, int start, int end) {
	if (start == end) {
		tree[node][0] = arr[start];
		tree[node][1] = start;
	}
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
	}
}

vector<int> query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return { 1000000001, 1000000001 };
	
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	vector<int> a = query(node << 1, start, mid, left, right);
	vector<int> b = query(node << 1 | 1, mid + 1, end, left, right);
	vector<int> minAB = min(a, b);
	return minAB;
}

void update(int node, int start, int end, int index, int val) {
	if (start == end) tree[node][0] = val;
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid)
			update(node << 1, start, mid, index, val);
		else
			update(node << 1 | 1, mid + 1, end, index, val);
		tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;
	arr.resize(N);
	tree.resize(N * 4, vector<int>(2));

	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	build(1, 0, N - 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			int idx, val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx - 1, val);
		}
		else if (c == 2) {
			vector<int> res(2);
			res = query(1, 0, N - 1, 0, N - 1);
			cout << res[1] + 1 << '\n';
		}
	}

	return 0;
}