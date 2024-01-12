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
				// 0 �̸� ����
				if ((s & (1 << k)) == 0) {
					// ���簪 �ڸ����� �ϳ� �ø��� �������
					nCur = nCur * 10 + vMap[i][j];
				}
				// ���θ� �������Ƿ� �׸� ����
				else {
					nSum += nCur;
					nCur = 0;
				}
			}
			nSum += nCur;
		}

		// ���η� Ž��
		for (int j= 0; j < m; j++) {
			int nCur = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				// 1 ����
				if ((s & (1 << k)) != 0) {
					// ���簪 �ڸ����� �ϳ� �ø��� �������
					nCur = nCur * 10 + vMap[i][j];
				}
				// ���θ� �������Ƿ� �׸� ����
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