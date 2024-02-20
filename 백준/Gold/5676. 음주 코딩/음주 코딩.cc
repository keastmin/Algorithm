#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tree;

void build(int node, int start, int end) {
	if (start == end) tree[node] = arr[start];
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);		
		tree[node] = tree[node << 1] * tree[node << 1 | 1];
	}
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	int a = query(node << 1, start, mid, left, right);
	int b = query(node << 1 | 1, mid + 1, end, left, right);
	return a * b;
}

void update(int node, int start, int end, int index, int val) {
	if (start == end) tree[node] = val;
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid)
			update(node << 1, start, mid, index, val);
		else
			update(node << 1 | 1, mid + 1, end, index, val);
		tree[node] = tree[node << 1] * tree[node << 1 | 1];
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	while (cin >> N >> K) {
		vector<char> res;
		arr.resize(N);
		tree.resize(N * 4);
		res;

		int t;
		for (int i = 0; i < N; i++) {
			cin >> t;

			if (t > 0) arr[i] = 1;
			else if (t < 0) arr[i] = -1;
			else arr[i] = 0;
		}

		build(1, 0, N - 1);

		char C;
		int a, b;
		for (int i = 0; i < K; i++) {
			cin >> C >> a >> b;

			if (C == 'C') {
				int r;
				if (b > 0) r = 1;
				else if (b < 0) r = - 1;
				else r = 0;
				update(1, 0, N - 1, a - 1, r);
			}
			else if (C == 'P') {
				int r = query(1, 0, N - 1, a - 1, b - 1);
				if (r > 0) res.push_back('+');
				else if (r < 0) res.push_back('-');
				else res.push_back('0');
			}
		}

		for (const auto r : res) {
			cout << r;
		}
		cout << '\n';
	}

	return 0;
}