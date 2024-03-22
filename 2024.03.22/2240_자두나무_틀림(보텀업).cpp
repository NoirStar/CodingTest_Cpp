#include <bits/stdc++.h>
using namespace std;

int T, W;

int dp[1001][31][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 자두 떨어지는초, 움직일수있는 수

	cin >> T >> W;

	vector<int> vZa(T+1);

	for (int i = 0; i < T; i++) {
		cin >> vZa[i];
	}


	// t 시간 w 횟수 p 1,2 나무
	// 가만히 있는경우
	// 1) 자두가 떨어지는 위치  dp[t][w][p] = dp[t-1][w][p] + 1
	// 2) 자두가 안떨어지는위치 dp[t][w][p] = dp[t-1][w][p]

	// 위치를 변경한 경우
	// 1) 자두가 떨어지는 위치 dp[t][w][p] = dp[t-1][w-1][3-p] + 1 (3-p 인이유는 1->2 2->1변경)
	// 2) 자두가 안떨어지는 위치 dp[t][w][p] = dp[t-1][w-1][3-p]
	
	// 초기 조건 설정
	for (int i = 0; i <= W; ++i) {
		dp[0][i][1] = 0; // 시작 위치는 1번 나무 아래
		dp[0][i][2] = -1; // 실제로는 도달할 수 없는 상태로 초기화
	}


	for (int t = 1; t <= T; t++) {
		for (int w = 0; w <= W; w++) {
			// 가만히 있는 경우
			dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w][1] + (vZa[t] == 1 ? 1 : 0));
			dp[t][w][2] = max(dp[t][w][2], dp[t - 1][w][2] + (vZa[t] == 2 ? 1 : 0));

			// 움직이는 경우
			if (w > 0) {
				dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][2] + (vZa[t] == 1 ? 1 : 0));
				dp[t][w][2] = max(dp[t][w][2], dp[t - 1][w - 1][1] + (vZa[t] == 2 ? 1 : 0));
			}
		}
	}
	
	int nRet = 0;
	for (int w = 0; w <= W; ++w) {
		nRet = max(nRet, max(dp[T][w][1], dp[T][w][2]));
	}

	cout << nRet;


	return 0;
}