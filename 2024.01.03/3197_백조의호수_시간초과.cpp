#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<char>> vMap;
vector<vector<int>> vVisited;
vector<vector<int>> vWater;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// 하루하루가 지날 때 마다 백조가 만날 수 있는지 체크한다.

void dfs(int y, int x) {
	vWater[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || vWater[ny][nx]) continue;

		if (vMap[y][x] == '.' && vMap[ny][nx] == 'X') {
			vMap[ny][nx] = '.';
			vWater[ny][nx] = 1;
		}
		else if (vMap[ny][nx] == '.') dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int x, y;
	vMap.assign(n, vector<char>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
			if (vMap[i][j] == 'L') {
				y = i;
				x = j;
			}
		}
	}
	
	
	int nDays = 0;
	while (true) {

		// 물의 dfs 실행
		vWater.assign(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vMap[i][j] == '.' && !vWater[i][j]) {
					dfs(i, j);
				}
			}
		}

		// 백조 이동
		bool bMeet = false;

		vVisited.assign(n, vector<int>(m, 0));
		queue<pair<int, int>> q;
		q.push({ y,x });
		vVisited[y][x] = 1;

		while (!q.empty()) {
			int ay, ax;
			tie(ay, ax) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = ay + dy[i];
				int nx = ax + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisited[ny][nx]) continue;

				if (vMap[ny][nx] == '.') {
					q.push({ ny,nx });
					vVisited[ny][nx] = 1;
				}
				else if (vMap[ny][nx] == 'L') {
					bMeet = true;
					break;
				}
			}
		}
		nDays++;
		if (bMeet) break;
	}

	cout << nDays;
	return 0;
}