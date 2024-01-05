#include <bits/stdc++.h>

using namespace std;

int n, m, len;
vector<vector<char>> vMap;
vector<vector<int>> vVisited;
vector<int> vRet;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x, int count) {
	if (y == 0 && x == m - 1) {
		vRet.push_back(count);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisited[ny][nx] || vMap[ny][nx] == 'T') continue;
		vVisited[ny][nx] = 1;
		dfs(ny, nx, count + 1);
		vVisited[ny][nx] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> len;

	vMap.assign(n, vector<char>(m, 0));
	vVisited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
		}
	}

	vVisited[n - 1][0] = 1;
	dfs(n - 1, 0, 1);

	sort(vRet.begin(), vRet.end());

	int nCount = 0;
	for (const auto& a : vRet) {
		if (len == a) nCount++;
	}
	cout << nCount;

	return 0;
}