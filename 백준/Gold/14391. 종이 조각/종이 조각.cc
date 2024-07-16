#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[4][4];
int res = -10e8;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
}

// 가로의 누적합 검사
void HorizontalSumCalc(int binary, int& sum) {
	for (int y = 0; y < N; y++) {
		int score = 0;
		for (int x = 0; x < M; x++) {
			int row = y * M + x;	// 비트마스킹을 위해 2차원 배열을 1차원 인덱스처럼 계산
									// 위의 예시는 보여주기 식이고, 실제 이진수는 111111111111 이런 식임
			if ((binary & (1 << row)) == 0) {	// 연속되는 가로일 때 점수 더해줌
				score = score * 10 + arr[y][x];
			}
			else {
				sum += score;
				score = 0;
			}
		}
		sum += score;
	}
}

// 세로의 누적합 검사
void VerticalSumCalc(int binary, int& sum) {
	for (int x = 0; x < M; x++) {
		int score = 0;
		for (int y = 0; y < N; y++) {
			int col = y * M + x;	// 비트마스킹을 위해 2차원 배열을 1차원 인덱스처럼 계산
									// 위의 예시는 보여주기 식이고, 실제 이진수는 111111111111 이런 식임
			if ((binary & (1 << col)) != 0) {	// 연속되는 세로일 때 점수 더해줌
				score = score * 10 + arr[y][x];
			}
			else {
				sum += score;
				score = 0;
			}
		}
		sum += score;
	}
}

/***************************************************
	1 << N * M의 의미

	- 비트마스킹을 위해
	- 만약 N이 3이고 M이 4라면 아래와 같다
	- 1 1 1 1
	- 1 1 1 1
	- 1 1 1 1
	- 위와 같이 N을 3칸, M이 4칸이 되어 0이면 가로 숫자 계산,
	- 1이면 세로 숫자 계산임을 비트마스킹을 통해 계산이 가능함
****************************************************/
void FindResult() {
	for (int i = 0; i < (1 << N * M); i++) {
		int sum = 0;
		HorizontalSumCalc(i, sum);
		VerticalSumCalc(i, sum);
		res = max(res, sum);
	}
}
int main() {
	Input();
	FindResult();
	cout << res << '\n';

	return 0;
}