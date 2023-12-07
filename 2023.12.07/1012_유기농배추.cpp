#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGraph;
vector<vector<bool>> vVisited;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x) {
	vVisited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || ny < 0 || ny >= vGraph.size() || nx >= vGraph[0].size()) continue;
		if (vGraph[ny][nx] == 1 && !vVisited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	int nTest;
	cin >> nTest;

	for (int t = 0; t < nTest; t++) {
		int nM, nN, nK;
		cin >> nM >> nN >> nK;

		vGraph.assign(nN, vector<int>(nM, 0));
		vVisited.assign(nN, vector<bool>(nM, 0));

		for (int i = 0; i < nK; i++) {
			int x, y;
			cin >> x >> y;
			vGraph[y][x] = 1;
		}

		int nRet = 0;
		for (int i = 0; i < nN; i++) {
			for (int j = 0; j < nM; j++) {
				if (vGraph[i][j] == 1 && !vVisited[i][j]) {
					nRet++;
					dfs(i, j);
				}
			}
		}
		cout << nRet << '\n';
	}

	return 0;
}