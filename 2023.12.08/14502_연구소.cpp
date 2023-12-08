#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vLab;
vector<vector<int>> vAfterLab;
vector<pair<int, int>> vZeroPos;
vector<pair<int, int>> vVirusPos;
vector<int> vRet;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int nVirus = 0;
int nWallCount = 3;

void dfs(int y, int x) {
	vAfterLab[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= vLab.size() || nx >= vLab[0].size()) continue;
		if (vAfterLab[ny][nx] == 0) {
			nVirus++;
			dfs(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	vLab.assign(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vLab[i][j];
			if (vLab[i][j] == 0) vZeroPos.push_back({ i,j });
			else if (vLab[i][j] == 2) vVirusPos.push_back({ i,j });
			else nWallCount++;
		}
	}

	vAfterLab.assign(vLab.begin(), vLab.end());

	// 조합으로 선택하여 벽세우기
	vector<bool> vCombi(vZeroPos.size(), false);
	vCombi[0] = true;
	vCombi[1] = true;
	vCombi[2] = true;

	do {
		vAfterLab.assign(vLab.begin(), vLab.end());
		for (int i = 0; i < vCombi.size(); i++) {
			if (vCombi[i] == true)
				vAfterLab[vZeroPos[i].first][vZeroPos[i].second] = 1;
		}
		// 바이러스 감염, 안전구역 계산
		nVirus = vVirusPos.size();
		for (const auto& v : vVirusPos) {
			dfs(v.first, v.second);
		}
		vRet.push_back((n * m) - nVirus - nWallCount);
		nVirus = 0;

	} while (prev_permutation(vCombi.begin(), vCombi.end()));

	cout << *max_element(vRet.begin(), vRet.end());

	return 0;
}