#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dx[] = {0, -1, 0, 1, 1, -1, 1, -1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;

	while (1) {
		cin >> n >> m;
		if (n == 0) break;

		vector<vector<char>> vMap(n, vector<char>(m, 0));
		vector<vector<char>> vRet(n, vector<char>(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> vMap[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int nCount = 0;
				for (int k = 0; k < 8; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (vMap[ny][nx] == '*') nCount++;
				}
				if (vMap[i][j] == '*') vRet[i][j] = '*';
				else vRet[i][j] = nCount + '0';
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << vRet[i][j];
			}
			cout << '\n';
		}
	}


	return 0;
}