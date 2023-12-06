#include <bits/stdc++.h>

using namespace std;

// 상하 좌우 이동을 위한 델타 배열
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<vector<int>> vGraph; // 그래프를 저장하는 배열
vector<vector<bool>> vVisited; // 방문 여부를 저장하는 배열

// 2차원배열일때는 반대이므로 
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	// 현재위치를 방문한 곳으로 설정한다.
	vVisited[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위를 넘어선다면 continue;
			if (ny < 0 || nx < 0 || ny >= vGraph.size() || nx >= vGraph[0].size()) continue;
			
			// 방문한적이 없는 곳이고, 길이 있는곳이면 push
			if (!vVisited[ny][nx] && vGraph[ny][nx] == 1) {
				q.push({ny, nx});
				vVisited[ny][nx] = true;
			}
		}
	}

	return;
}