#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string calc;
	stack<char> stk;
	cin >> calc;

	bool check = false;
	for (const auto c : calc) {
		if (c >= 'A' && c <= 'Z') {
			cout << c;
		}
		else {
			if (c == '(') {
				stk.push(c);
			}
			else if (c == ')') {
				while (stk.top() != '(') {
					cout << stk.top();
					stk.pop();
				}
				stk.pop();
			}
			else if (c == '*' || c == '/') {
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
					cout << stk.top();
					stk.pop();
				}
				stk.push(c);
			}
			else if (c == '+' || c == '-') {
				while (!stk.empty() && (stk.top() != '(')) {
					cout << stk.top();
					stk.pop();
				}
				stk.push(c);
			}		
		}
	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}


	return 0;
}