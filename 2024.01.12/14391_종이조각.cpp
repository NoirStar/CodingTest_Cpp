#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vMap;
vector<vector<int>> vVisited;

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vMap.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			vMap[i][j] = s[j] - '0';
		}
	}

	int nMax = 0;
	for (int s = 0; s < (1 << (n * m)); s++) {
		int nSum = 0;
		for (int i = 0; i < n; i++) {
			int nCur = 0;
			for (int j = 0; j < m; j++) {
				int k = j + i * m;
				// 0 이면 가로
				if ((s & (1 << k)) == 0) {
					// 현재값 자리수를 하나 올리고 계속진행
					nCur = nCur * 10 + vMap[i][j];
				}
				// 세로를 만났으므로 그만 진행
				else {
					nSum += nCur;
					nCur = 0;
				}
			}
			nSum += nCur;
		}

		// 세로로 탐색
		for (int j= 0; j < m; j++) {
			int nCur = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				// 1 세로
				if ((s & (1 << k)) != 0) {
					// 현재값 자리수를 하나 올리고 계속진행
					nCur = nCur * 10 + vMap[i][j];
				}
				// 가로를 만났으므로 그만 진행
				else {
					nSum += nCur;
					nCur = 0;
				}
			}
			nSum += nCur;
		}
		nMax = max(nMax, nSum);
	}

	cout << nMax;


	return 0;
}