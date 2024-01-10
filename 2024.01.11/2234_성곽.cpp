#include<bits/stdc++.h>

using namespace std;

int n, m, nRoom = 0, nPlusMax = 0;
int nMax = -987654321;
vector<vector<int>> vMap;
vector<vector<int>> vVisited;
vector<int> vRoom;

// 이것도 맞춰줘야함..
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

// 방의개수는 분리된 컴포넌트의 개수

// 서 1 북 2 동 4 남 8

int dfs(int y, int x, int count) {

	if (vVisited[y][x]) return 0; // for문안에서 체크하는것과 동일한 방식
	vVisited[y][x] = count;
	
	int nRet = 1;
	for (int i = 0; i < 4; i++) {
		// 길이 있으면
		if (!(vMap[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];

			nRet += dfs(ny, nx, count);
		}
	}
	return nRet;
}

// 벽을 제거하는것 => connected 컴포넌트들 간에 구분할 수 있는 id가 필요하다.

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	
	vMap.assign(n, vector<int>(m, 0));
	vVisited.assign(n, vector<int>(m, 0));
	vRoom.assign(n*m+1,0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vVisited[i][j]) {
				nRoom++; // 컴포넌트를 구분할 수 있는 id
				vRoom[nRoom] = dfs(i, j, nRoom); // id별 방 개수
				nMax = max(nMax, vRoom[nRoom]);
			}
		}
	}

	// 벽을 부셔서 max값 구하기 서로 다른 컨포넌트간 (1차이나는) 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {
				int a1 = vVisited[i + 1][j];
				int a2 = vVisited[i][j];
				if(a1 != a2)
					nPlusMax = max(nPlusMax, vRoom[a1] + vRoom[a2]);
			}
			if (j + 1 < m) {
				int a1 = vVisited[i][j + 1];
				int a2 = vVisited[i][j];
				if (a1 != a2)
					nPlusMax = max(nPlusMax, vRoom[a1] + vRoom[a2]);
			}
		}
	}
	cout << nRoom << '\n' << nMax << '\n' << nPlusMax;
	return 0;
}