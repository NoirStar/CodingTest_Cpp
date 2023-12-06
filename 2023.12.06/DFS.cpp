#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGrid;
vector<vector<bool>> vVisited;

// ���� �¿� �̵��� ���� ��Ÿ �迭
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// 2�����迭�϶��� �ݴ��̹Ƿ� 
void dfs(int y, int x) {
	vVisited[y][x] = true; // ���� ��ġ �湮ó��

	// ���� �¿�� ������ ��ġ Ž��
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// �迭 ������ ����ų� �̹� �湮�� ��ġ��� ��ŵ
		if (ny < 0 || nx < 0 || ny >= vGrid.size() || nx >= vGrid[0].size()) { 
			continue;
		}
		
		// �� �� �ִ� ���̰� �湮������ ���� ���̸� ��� Ž��
		if (vGrid[ny][nx] == 1 && !vVisited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}