#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, hIdx;
int arr[100001];
int pq[100010];

void h_swap(int idx1, int idx2) {
	int tmp = pq[idx1];
	pq[idx1] = pq[idx2];
	pq[idx2] = tmp;
}

void h_push(int data) {
	int idx = ++hIdx;
	pq[idx] = data;
	while ((idx != 1) && (data < pq[idx / 2])) {
		h_swap(idx, idx / 2);
		idx /= 2;
	}
}

int h_pop() {
	int res = pq[1];
	pq[1] = pq[hIdx--];

	int parent = 1;
	int child;
	while (1) {
		child = parent * 2;
		if (child + 1 <= hIdx && pq[child + 1] < pq[child]) child++;
		if (child > hIdx || pq[parent] < pq[child]) break;
		h_swap(child, parent);
		parent = child;
	}

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) h_push(arr[i]);

	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		int sum = h_pop() + h_pop();
		ans += sum;
		h_push(sum);
	}

	cout << ans << '\n';
	
	return 0;
}