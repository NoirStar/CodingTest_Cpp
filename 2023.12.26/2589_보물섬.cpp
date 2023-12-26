#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> vTre;
vector<vector<int>> vVisited;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1 ,0 };

int nMax = 0;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	vVisited[y][x] = 1;
	q.push({y, x});

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || ny < 0 || ny >= vTre.size() || nx >= vTre[0].size()) continue;
			if (vVisited[ny][nx] > 0) continue;

			if (vTre[ny][nx] == 'L') {
				q.push({ny,nx});
				vVisited[ny][nx] = vVisited[y][x] + 1;
				nMax = max(nMax, vVisited[y][x]);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nN, nM;
	cin >> nN >> nM;

	vector<int> vRet;

	vTre.assign(nN, vector<char>(nM, 0));

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nM; j++) {
			cin >> vTre[i][j];
		}
	}

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nM; j++) {
			if (vTre[i][j] == 'L') {
				vVisited.assign(nN, vector<int>(nM, 0));
				nMax = 0;
				bfs(i, j);
				vRet.push_back(nMax);
			}
		}
	}

	cout << *max_element(vRet.begin(), vRet.end());


	return 0;
}