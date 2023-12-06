#include <bits/stdc++.h>

using namespace std;

// ���� �¿� �̵��� ���� ��Ÿ �迭
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<vector<int>> vGraph; // �׷����� �����ϴ� �迭
vector<vector<bool>> vVisited; // �湮 ���θ� �����ϴ� �迭

// 2�����迭�϶��� �ݴ��̹Ƿ� 
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	// ������ġ�� �湮�� ������ �����Ѵ�.
	vVisited[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// ������ �Ѿ�ٸ� continue;
			if (ny < 0 || nx < 0 || ny >= vGraph.size() || nx >= vGraph[0].size()) continue;
			
			// �湮������ ���� ���̰�, ���� �ִ°��̸� push
			if (!vVisited[ny][nx] && vGraph[ny][nx] == 1) {
				q.push({ny, nx});
				vVisited[ny][nx] = true;
			}
		}
	}

	return;
}