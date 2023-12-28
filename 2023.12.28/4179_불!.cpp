#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> vMap;
vector<vector<int>> vFireVi;
vector<vector<int>> vJihoonVi;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// 불보다 지훈이가 빠르면 갈 수 있다. 두개의 최단거리를 비교한다.
// 최단거리 그리고 가중치가 일정하면 bfs

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	pair<int, int> start;
	vMap.assign(n, vector<char>(m, 0));
	vFireVi.assign(n, vector<int>(m, 0));
	vJihoonVi.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
			if (vMap[i][j] == 'J')  start = make_pair(i, j);
			else if (vMap[i][j] == 'F') {
				vFireVi[i][j] = 1;
				q.push({ i, j });
			}
		}
	}


	// 불의 최단거리
	int x, y;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vFireVi[ny][nx] > 0) continue;

			if (vMap[ny][nx] != '#') {
				vFireVi[ny][nx] = vFireVi[y][x] + 1;
				q.push({ ny, nx });
			}

		}
	}

	// 지훈이의 최단거리
	int nMinRet = 100000000;
	y = start.first;
	x = start.second;
	q.push({y, x});
	vJihoonVi[y][x] = 1;

	if (y == n - 1 || x == m - 1 || y == 0 || x == 0) {
		cout << 1;
		return 0;
	}

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vJihoonVi[ny][nx] > 0) continue;

			if (vMap[ny][nx] == '.' && ((vFireVi[ny][nx] > vJihoonVi[y][x] + 1) || vFireVi[ny][nx] == 0)) {
				vJihoonVi[ny][nx] = vJihoonVi[y][x] + 1;
				q.push({ ny, nx });
			}

			if (vJihoonVi[ny][nx] != 0 && (ny == n - 1 || nx == m - 1 || ny == 0 || nx == 0)) {
				nMinRet = min(nMinRet, vJihoonVi[ny][nx]);
			}
		}
	}

	if (nMinRet == 100000000) cout << "IMPOSSIBLE";
	else cout << nMinRet;

	return 0;
}