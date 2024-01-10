#include<bits/stdc++.h>

using namespace std;

int n, m, nRoom = 0, nPlusMax = 0;
int nMax = -987654321;
vector<vector<int>> vMap;
vector<vector<int>> vVisited;
vector<int> vRoom;

// �̰͵� ���������..
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

// ���ǰ����� �и��� ������Ʈ�� ����

// �� 1 �� 2 �� 4 �� 8

int dfs(int y, int x, int count) {

	if (vVisited[y][x]) return 0; // for���ȿ��� üũ�ϴ°Ͱ� ������ ���
	vVisited[y][x] = count;
	
	int nRet = 1;
	for (int i = 0; i < 4; i++) {
		// ���� ������
		if (!(vMap[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];

			nRet += dfs(ny, nx, count);
		}
	}
	return nRet;
}

// ���� �����ϴ°� => connected ������Ʈ�� ���� ������ �� �ִ� id�� �ʿ��ϴ�.

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
				nRoom++; // ������Ʈ�� ������ �� �ִ� id
				vRoom[nRoom] = dfs(i, j, nRoom); // id�� �� ����
				nMax = max(nMax, vRoom[nRoom]);
			}
		}
	}

	// ���� �μż� max�� ���ϱ� ���� �ٸ� ������Ʈ�� (1���̳���) 
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