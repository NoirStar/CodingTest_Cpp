#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<char>> vMap, vMapPrev;
vector<vector<int>> vVisited;
vector<vector<int>> vWater;

int nDays = 0;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// 하루하루가 지날 때 마다 백조가 만날 수 있는지 체크한다.

void bfs(int y, int x) {
	vWater[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vWater[ny][nx] > nDays) continue;

			if (vMap[y][x] == '.' && vMap[ny][nx] == 'X') {
				vMap[ny][nx] = '.';
				vWater[ny][nx] = nDays+1;
			}
			else if (vMap[ny][nx] == '.') {
				q.push({ ny,nx });
				vWater[ny][nx] = nDays + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int x, y;
	vMap.assign(n, vector<char>(m, 0));
	vWater.assign(n, vector<int>(m, 0));
	vVisited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
			if (vMap[i][j] == 'L') {
				y = i;
				x = j;
			}
		}
	}



	// 굳이 매번 백조의 bfs를 돌릴 필요가 없다. n일에 못만난다면 n-1일에도 못만나기때문
	bool bBinary = true;

	while (true) {

		// 물의 bfs 실행
		vMapPrev = vMap;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vMap[i][j] == '.' && vWater[i][j] <= nDays) {
					bfs(i, j);
				}
			}
		}

		// 백조 이동
		bool bMeet = false;
		bBinary = nDays % 2;
		if (bBinary) {
			queue<pair<int, int>> q;
			q.push({ y,x });
			vVisited[y][x] = nDays+1;

			while (!q.empty()) {
				int ay, ax;
				tie(ay, ax) = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = ay + dy[i];
					int nx = ax + dx[i];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisited[ny][nx] > nDays) continue;

					if (vMap[ny][nx] == '.') {
						q.push({ ny,nx });
						vVisited[ny][nx] = nDays+1;
					}
					else if (vMap[ny][nx] == 'L') {
						bMeet = true;
						break;
					}
				}
			}

			// 만약 만낫다면, 이 전일에 만낫을 수도 있으므로 한번더 진행
			if (bMeet) {
				vVisited.assign(n, vector<int>(m, 0));
				bool bPrevMeet = false;
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

						if (vMapPrev[ny][nx] == '.') {
							q.push({ ny,nx });
							vVisited[ny][nx] = 1;
						}
						else if (vMapPrev[ny][nx] == 'L') {
							bPrevMeet = true;
							break;
						}
					}
				}
				if (bPrevMeet) break;
			}
		}
		
		nDays++;
		if (bMeet) break;
	}

	cout << nDays;
	return 0;
}