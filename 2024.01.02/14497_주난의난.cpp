#include <bits/stdc++.h>

using namespace std;
int n, m;
bool bFound = false;

vector<vector<char>> vClass;
vector<vector<bool>> vVisited;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs(int y, int x) {
	vVisited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		tie(y,x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisited[ny][nx]) continue;

			if (vClass[ny][nx] == '1') {
				vClass[ny][nx] = '0';
				vVisited[ny][nx] = true;
			}
			else if (vClass[ny][nx] == '#') {
				bFound = true;
				break;
			}
			else if (vClass[ny][nx] == '0') {
				q.push({ ny,nx });
				vVisited[ny][nx] = true;
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vClass.assign(n, vector<char>(m, 0));
	
	int y, x;
	pair<int, int> a1, a2;
	cin >> y >> x;
	a1 = { y, x };
	cin >> y >> x;
	a2 = { y, x };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vClass[i][j];
		}
	}

	int nCount = 0;
	while (true) {
		if (bFound) break;
		vVisited.assign(n, vector<bool>(m, 0));
		nCount++;
		bfs(a1.first - 1, a1.second - 1);
	}

	cout << nCount <<'\n';

	return 0;
}