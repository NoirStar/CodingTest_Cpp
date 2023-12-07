#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGraph;
vector<vector<bool>> vVisited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs(int y, int x, int& w) {
	vVisited[y][x] = true;
	w++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= vGraph.size() || nx >= vGraph[0].size()) continue;
		if (vGraph[ny][nx] == 1 && !vVisited[ny][nx]) {
			bfs(ny, nx, w);
		}
	}
	return;
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	vGraph.assign(m, vector<int>(n, 1));
	vVisited.assign(m, vector<bool>(n, 0));

	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				vGraph[y][x] = 0;
			}
		}
	}

	int nRet = 0;
	vector<int> vWidth;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vGraph[i][j] == 1 && !vVisited[i][j]) {
				int nWidth = 0;
				nRet++;
				bfs(i, j, nWidth);
				vWidth.push_back(nWidth);
			}
		}
	}
	sort(vWidth.begin(), vWidth.end());
	cout << nRet << '\n';
	for (const auto& w : vWidth) cout << w << ' ';

	return 0;
}