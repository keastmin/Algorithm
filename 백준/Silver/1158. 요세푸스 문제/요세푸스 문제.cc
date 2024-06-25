#include <iostream>
#include <vector>
using namespace std;

struct List {
	int num;
	List* next;
};

List* NewNode(int n) {
	List* node = new List;
	node->num = n;
	node->next = nullptr;
	return node;
}

List* head = NewNode(1);
int N, K;

int main() {
	cin >> N >> K;
	head->next = head;
	List* tmp = head;
	for (int i = 2; i <= N; i++) {
		List* node = NewNode(i);
		tmp->next = node;
		tmp = tmp->next;
	}
	tmp->next = head;
	
	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			tmp = tmp->next;
		}

		if (i < N - 1)
			cout << tmp->next->num << ", ";
		else
			cout << tmp->next->num;

		tmp->next = tmp->next->next;
	}
	cout << ">";

	delete head;

	return 0;
}