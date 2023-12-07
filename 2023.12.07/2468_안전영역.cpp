#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGraph;
vector<vector<bool>> vVisited;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x, int h) {
	vVisited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || ny < 0 || ny >= vGraph.size() || nx >= vGraph[0].size()) continue;
		if (vGraph[ny][nx] > h && !vVisited[ny][nx]) {
			dfs(ny, nx, h);
		}
	}
	return;
}

int main() {
	int nMap, nMax = 0;
	cin >> nMap;

	vGraph.assign(nMap, vector<int>(nMap, 0));
	vVisited.assign(nMap, vector<bool>(nMap, 0));

	for (int i = 0; i < nMap; i++) {
		for (int j = 0; j < nMap; j++) {
			cin >> vGraph[i][j];
			nMax = max(nMax, vGraph[i][j]);
		}
	}

	int nSafeMax = 0;
	for (int h = 0; h < nMax; h++) {
		int nSafe = 0;
		vVisited.assign(nMap, vector<bool>(nMap, 0));
		for (int i = 0; i < nMap; i++) {
			for (int j = 0; j < nMap; j++) {
				if (vGraph[i][j] > h && !vVisited[i][j]) {
					dfs(i, j, h);
					nSafe++;
				}
			}
		}
		nSafeMax = max(nSafeMax, nSafe);
	}

	cout << nSafeMax;

	return 0;
}