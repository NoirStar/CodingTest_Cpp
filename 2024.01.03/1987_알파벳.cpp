#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> vMap;

// ���ĺ� �ߺ�üũ �迭
vector<int> vVisited(27);

int r, c, nRet = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int nCount) {

	nRet = max(nRet, nCount);
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= r || nx >= c ) continue;
		int next = (int)(vMap[ny][nx] - 'A');

		if (vVisited[next] == 0) {
			vVisited[next] = 1;
			dfs(ny, nx, nCount + 1);
			// ���� ����. ���ٰ� �ٸ���� �������ؼ� �ٸ� ����� ���� ���°� ���������� �ȵǹǷ�
			vVisited[next] = 0;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	vMap.assign(r, vector<char>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> vMap[i][j];
		}
	}

	vVisited[(int)vMap[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << nRet;

	return 0;
}