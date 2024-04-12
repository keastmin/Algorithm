/**********************************************************
2024-04-12
https://github.com/keastmin
백준/11066/파일 합치기
난이도: 골드3
유형: 다이나믹 프로그래밍(DP)
**********************************************************/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 테스트 케이스
	int T;
	cin >> T;
	while (T--) {
		
		// 파일의 개수
		int K;
		cin >> K;

		// 각 파일의 비용
		vector<int> arr(K + 1);
		// 파일을 합치는데 소요되는 비용 dp 벡터
		// ex) dp[1][4]: 첫 번째 파일부터 4번째 파일까지 합치는데 소요되는 비용
		vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));
		// 전체 소요되는 비용의 합
		vector<int> sum(K + 1, 0);

		// 각 파일의 합치는데 필요한 비용과 그 비용의 합 저장
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		// i: dp[dx][dy]에서 dx와 dy 사이의 길이, 즉 처음과 끝 사이의 길이
		for (int i = 1; i < K; i++) {

			// dx: 파일을 합칠 때 처음이 되는 인덱스, 즉 시작부터 끝까지의 길이가 K를 넘으면 안됌
			for (int dx = 1; dx + i <= K; dx++) {

				// dy: 파일을 합칠 때 끝이 되는 인덱스, 즉 dx부터 i만큼의 길이를 더하면 dy
				int dy = dx + i;

				// dp를 위해 dx부터 dy까지의 파일을 합치는데 소요되는 비용의 합을 최대값으로 설정
				dp[dx][dy] = numeric_limits<int>::max();

				/**********************************************
				mid: 구해야 하는 범위를 두 부분으로 나누는 기준점
				
				mid로 구분하는 이유는 아래와 같은 소요 비용이 있을 때,
				[1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13]
				 1   21  3   4   5   35  5   4   3    5   98   21   14
				
				여기서 dp[4][11]을 구한다고 가정하면 범위를 뜻하는 i는 7이고
				시작하는 dx = 4, 끝을 뜻하는 dy = 11이다.

				여기서 중요한 점은 파일 전체의 합산을 계산하는 것이 아닌
				(각 파일의 소요시간) + (전체 파일을 합치는데 소요된 시간)이다.

				그러므로 반드시 두 개의 파일을 합산하는 경우의 수가 필요한 것이다.
				[4]/[5, 6, 7, 8, 9, 10, 11]
				[4, 5]/[6, 7, 8, 9, 10, 11]
				[4, 5, 6]/[7, 8, 9, 10, 11]
				. . .
				[4, 5, 6, 7, 8, 9, 10]/[11]
				과 같은 경우들이 가능하며 dp[4][11] = min(dp[4][11], dp[4][5] + dp[6][11] + sum[11] - sum[3])이 되는 것이다.
				여기서 dp[4][5]와 dp[6][11]은 이미 계산되고 저장된 두 파일의 합산 총합이고 새로 저장될 dp[4][11]은
				두 파일의 합산 총합의 최솟값에 파일을 합칠 범위의 총합을 더해준 값이다.
				***********************************************/
				for (int mid = dx; mid < dy; mid++) {
					dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + sum[dy] - sum[dx - 1]);
				}
			}
		}

		// 처음부터 끝까지 합치는데 소요되는 비용의 최솟값 출력
		cout << dp[1][K] << '\n';
	}

	return 0;
}