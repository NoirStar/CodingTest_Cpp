#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

vector<vector<int>> vBoard;
vector<vector<int>> vVisited;

void bfs(int y, int x) {
	vVisited[y][x] = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		tie(y,x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= vBoard.size() || nx >= vBoard[0].size()) continue;

			if (vVisited[ny][nx] == 0 && vBoard[ny][nx] == 1) {
				vVisited[ny][nx] = vVisited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int sy = 0, sx = 0;

	vBoard.assign(n, vector<int>(m, 0));
	vVisited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vBoard[i][j];
			if (vBoard[i][j] == 2) {
				sy = i;
				sx = j;
			}
		}
	}
	bfs(sy, sx);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vVisited[i][j] == 0 && vBoard[i][j] == 1) cout << -1 << ' ';
			else cout << vVisited[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}