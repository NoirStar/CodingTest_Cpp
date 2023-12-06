#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<vector<int>> vGraph;
	vector<vector<int>> vVisited;

	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { -1, 0, 1, 0 };

	int n, m;
	cin >> n >> m;

	vGraph.assign(n, vector<int>(m, 0));
	vVisited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			vGraph[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	
	// 시작 위치 세팅
	vVisited[0][0] = 1;
	q.push({0, 0});
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || ny >= n || nx >= m) continue;

			if (vGraph[ny][nx] == 1 && !vVisited[ny][nx]) {
				vVisited[ny][nx] = vVisited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	cout << vVisited[n - 1][m - 1];

	return 0;
}