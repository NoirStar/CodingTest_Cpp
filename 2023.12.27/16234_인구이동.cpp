#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vMap;
vector<vector<int>> vVisited;
vector<pair<int,int>> vOpenList;

int n, nMin, nMax;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0 ,1 };

void dfs(int y, int x) {

	vVisited[y][x] = 1;
	vOpenList.push_back({ y,x });

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || vVisited[ny][nx]) continue;

		int nComp = abs(vMap[ny][nx] - vMap[y][x]);

		if (nComp >= nMin && nComp <= nMax) {
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> nMin >> nMax;

	vMap.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vMap[i][j];
		}
	}

	int nDays = 0;
	while (true) {
		bool bEnd = false;
		vVisited.assign(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vVisited[i][j]) {
					vOpenList.clear();
					dfs(i, j);

					if (vOpenList.size() == 1) continue;
					int avg, sum = 0;
					for (auto v : vOpenList) {
						sum += vMap[v.first][v.second];
					}
					avg = sum / vOpenList.size();
					for (auto v : vOpenList) {
						vMap[v.first][v.second] = avg;
					}
					bEnd = true;

				}
			}
		}
		if (!bEnd) break;
		else nDays++;
	}

	cout << nDays;


	return 0;
}
