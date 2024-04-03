#include<iostream>
using namespace std;
int main() {
	double score[1000];
	int N, max = 0;
	double sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if (max < score[i])
			max = score[i];
	}

	for (int i = 0; i < N; i++) {
		score[i] = (score[i] / max) * 100;
		sum += score[i];
	}

	sum = sum / N;

	cout.precision(5);
	cout << sum << '\n';

	return 0;
}