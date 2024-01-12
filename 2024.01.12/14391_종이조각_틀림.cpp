#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> vMap;
vector<vector<int>> vVisited;

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vMap.assign(n, vector<char>(m, 0));

	int nMax = 0;
	for (int i = 0; i < (1<<n*m); i++) {
		int nSum = 0;
		vVisited.assign(n, vector<int>(m, 0));
		for (int j = 0; j < n * m; j++) {

			string s;
			int nRealX = j % m;
			int nRealY = j / m;
			int k = nRealX + nRealY * m;
			if (vVisited[nRealY][nRealX]) continue;

			if (i & (1 << j)) {
				while (nRealX < m) {
					if (vVisited[nRealY][nRealX] || (i&(1<<k)) ==0 ) break;
					s += vMap[nRealY][nRealX];
					vVisited[nRealY][nRealX] = 1;
					nRealX++;
					k = nRealX + nRealY * m;
				}
				nSum += stoi(s);
			}
			else {
				while (nRealY < n) {
					if (vVisited[nRealY][nRealX] || (i & (1 << k)) == 1) break;
					s += vMap[nRealY][nRealX];
					vVisited[nRealY][nRealX] = 1;
					nRealY++;
					k = nRealX + nRealY * m;
				}
				nSum += stoi(s);
			}
		}
		nMax = max(nMax, nSum);
	}

	cout << nMax;

	return 0;
}