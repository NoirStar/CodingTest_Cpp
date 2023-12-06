#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGrid;
vector<vector<bool>> vVisited;

// 상하 좌우 이동을 위한 델타 배열
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// 2차원배열일때는 반대이므로 
void dfs(int y, int x) {
	vVisited[y][x] = true; // 현재 위치 방문처리

	// 상하 좌우로 인접한 위치 탐색
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 배열 범위를 벗어나거나 이미 방문한 위치라면 스킵
		if (ny < 0 || nx < 0 || ny >= vGrid.size() || nx >= vGrid[0].size()) { 
			continue;
		}
		
		// 갈 수 있는 곳이고 방문한적이 없는 곳이면 재귀 탐색
		if (vGrid[ny][nx] == 1 && !vVisited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}