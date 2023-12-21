#include <bits/stdc++.h>

using namespace std;

int dz[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 1, 0, -1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };

struct Point{
	int z;
	int y;
	int x;
};

vector<vector<vector<int>>> vTomato;
vector<vector<vector<int>>> vVisited;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m, n, h;
	cin >> m >> n >> h;

	int nTemp, nTomato = 0;
	vTomato.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	vVisited.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	queue<Point> q;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> vTomato[k][i][j];
				if (vTomato[k][i][j] == 0) nTomato++;
				else if (vTomato[k][i][j] == 1) {
					vVisited[k][i][j] = 1;
					q.push({ k,i,j });
				} 
			}
		}
	}

	if (nTomato == 0) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		Point p1 = q.front();
		int x, y, z;
		x = p1.x;
		y = p1.y;
		z = p1.z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = dz[i] + z;
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (nz < 0 || ny < 0 || nx < 0 ||
				nz >= vTomato.size() || ny >= vTomato[0].size() || nx >= vTomato[0][0].size()) continue;

			if (vVisited[nz][ny][nx] > 0 || vTomato[nz][ny][nx] == -1) continue;

			if (vTomato[z][y][x] == 1 && vTomato[nz][ny][nx] == 0) {
				vTomato[nz][ny][nx] = 1;
				vVisited[nz][ny][nx] = vVisited[z][y][x] + 1;
			}
			q.push({ nz,ny,nx });
		}
	}

	int nDays = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vTomato[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				nDays = max(nDays, vVisited[k][i][j]);
			}
		}
	}

	cout << nDays-1;

	return 0;
}