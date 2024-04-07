#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num;
	Node* left;
	Node* right;
};

Node* newNode(int n) {
	Node* node = new Node;
	node->num = n;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

Node* root;

void linkNode(int n) {
	Node* tmp = root;

	while (tmp != nullptr) {
		//cout << tmp->num << '\n';

		if (tmp->num < n) {
			if (tmp->right == nullptr) {
				Node* node = newNode(n);
				tmp->right = node;
				break;
			}
			tmp = tmp->right;
		}
		else {
			if (tmp->left == nullptr) {
				Node* node = newNode(n);
				tmp->left = node;
				break;
			}
			tmp = tmp->left;
		}
	}

	//cout << "success" << '\n';
}

void printTree(Node* r) {
	if (r != nullptr) {
		printTree(r->left);
		printTree(r->right);
		cout << r->num << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	root = newNode(a);

	while (1) {
		cin >> a;
		if (cin.eof()) break;
		linkNode(a);
	}

	Node* tmp = root;
	printTree(tmp);

	return 0;
}