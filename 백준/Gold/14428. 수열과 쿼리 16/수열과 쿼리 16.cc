/**********************************************************
2024-02-17
https://github.com/keastmin
백준/14428/수열과 쿼리 16
난이도: 골드1
유형: 세그먼트 트리
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;	// 입력받는 수를 저장하는 벡터
vector<vector<int>> tree;	// 세그먼트 트리를 구성하는 벡터

// 세그먼트 트리 구성
void build(int node, int start, int end) {
	// 리프 노드에 해당하는 값에 대한 저장
	if (start == end) {
		tree[node][0] = arr[start];
		tree[node][1] = start;
	}
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);		// 트리의 왼쪽 아래
		build(node << 1 | 1, mid + 1, end);	// 트리의 오른쪽 아래

		// 자신의 자식 노드 중 최솟값 저장
		tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
	}
}

vector<int> query(int node, int start, int end, int left, int right) {
	// 쿼리의 범위를 벗어나면 연산에 영향을 미치지 않는 값 리턴
	if (left > end || right < start) return { 1000000001, 1000000001 };

	// 쿼리 범위에 속하면 해당 노드 리턴
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	vector<int> a = query(node << 1, start, mid, left, right);
	vector<int> b = query(node << 1 | 1, mid + 1, end, left, right);

	// 쿼리의 범위에 속하는 노드 중 최솟값과 최댓값을 구분
	vector<int> minAB = min(a, b);
	return minAB;
}

void update(int node, int start, int end, int index, int val) {
	if (start == end) tree[node][0] = val;
	else {
		int mid = (start + end) >> 1;
		if (start <= index && index <= mid) {
			update(node << 1, start, mid, index, val);
		}
		else {
			update(node << 1 | 1, mid + 1, end, index, val);
		}
		tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;

	// 벡터 크기 지정
	arr.resize(N);
	tree.resize(N * 4, vector<int>(2));	// 통상적으로 기존 벡터의 4배, {MIN, MAX}
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 세그먼트 트리 구성
	build(1, 0, N - 1);

	vector<int> res(2);

	// 쿼리 입력 받기
	cin >> M;
	for (int i = 0; i < M; i++) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 1) update(1, 0, N - 1, a - 1, b);
		else if (c == 2) {
			res = query(1, 0, N - 1, a - 1, b - 1);
			cout << res[1] + 1 << '\n';
		}
	}

	return 0;
}