#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> party[51];
unordered_map<int, bool> truth;

void bfs(vector<int> m) {
	queue<int> q;
	for (int i = 0; i < m.size(); i++)
		q.push(m[i]);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (const auto p : party[curr]) {
			if (!truth[p]) {
				truth[p] = true;
				q.push(p);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, TN;

	vector<int> tMember;
	cin >> N >> M >> TN;	
	int member;
	for (int i = 0; i < TN; i++) {
		cin >> member;
		tMember.push_back(member);
		truth[member] = true;
	}

	int res = 0;
	vector<vector<int>> partyCase(M);
	for (int i = 0; i < M; i++) {
		int p;
		cin >> p;
		int t;
		cin >> t;
		partyCase[i].resize(p);
		partyCase[i][0] = t;
		for (int j = 1; j < p; j++) {
			int num;
			cin >> num;
			partyCase[i][j] = num;
			party[t].push_back(num);
			party[num].push_back(t);
		}
	}

	bfs(tMember);

	for (const auto pc : partyCase) {
		bool r = false;
		for (const auto p : pc) {
			//cout << p << ' ' << truth[p] << '\n';

			if (truth[p]) {
				r = true;
				break;
			}
		}

		if (!r) res++;
	}

	cout << res << '\n';

	return 0;
}