#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vCheeze;
vector<vector<bool>> vVisited;
vector<int> vRet;
int nCount = 0;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
	vVisited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= vCheeze.size() || nx >= vCheeze[0].size()) continue;
		if (vCheeze[y][x] == 0 && vCheeze[ny][nx] == 1) {
			vCheeze[ny][nx] = 0;
			vVisited[ny][nx] = true;
			nCount++;
		}
		else if (!vVisited[ny][nx] && !vCheeze[ny][nx]) dfs(ny, nx);
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;

	vCheeze.assign(n, vector<int>(m, 0));
	vVisited.assign(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vCheeze[i][j];
		}
	}
	
	while (true) {
		dfs(0, 0);

		vVisited.assign(n, vector<bool>(m, 0));
		if (nCount == 0) break;
		vRet.push_back(nCount);
		nCount = 0;
	}
	cout << vRet.size() << '\n' << vRet.back();
	
	return 0;
}