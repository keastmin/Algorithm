#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

struct Node {
	char c;
	Node* left;
	Node* right;
};

Node* newNode(char alp) {
	Node* node = new Node;
	node->c = alp;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

Node* root = newNode('A');

void FindNode(Node* tmp, char p, char lC, char rC) {
	if (tmp->c == p) {
		tmp->left = newNode(lC);
		tmp->right = newNode(rC);
	}
	if (tmp->left != nullptr) FindNode(tmp->left, p, lC, rC);
	if (tmp->right != nullptr) FindNode(tmp->right, p, lC, rC);
}

void CaseInput() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char p, lC, rC;
		cin >> p >> lC >> rC;

		Node* tmp = root;
		FindNode(tmp, p, lC, rC);
	}
}

void PrintPreOrder(Node* curr) {
	if (curr->c != '.') {
		cout << curr->c;
		PrintPreOrder(curr->left);
		PrintPreOrder(curr->right);
	}
}

void PrintInOrder(Node* curr) {
	if (curr->c != '.') {
		PrintInOrder(curr->left);
		cout << curr->c;
		PrintInOrder(curr->right);
	}
}

void PrintPostOrder(Node* curr) {
	if (curr->c != '.') {
		PrintPostOrder(curr->left);
		PrintPostOrder(curr->right);
		cout << curr->c;
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	CaseInput();

	Node* tmp = root;
	PrintPreOrder(tmp);
	cout << '\n';
	tmp = root;
	PrintInOrder(tmp);
	cout << '\n';
	tmp = root;
	PrintPostOrder(tmp);
	cout << '\n';

	return 0;
}