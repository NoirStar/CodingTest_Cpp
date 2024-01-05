#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vMap;
vector<vector<int>> vVisited;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };

int nMin = 987654321;
int n;

bool CheckFlower(int y, int x) {
	if (vVisited[y][x]) return false;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || vVisited[ny][nx]) return false;
	}
	return true;
}

int SetFlower(int y, int x) {
	int sum = vMap[y][x];
	vVisited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		vVisited[ny][nx] = 1;
		sum += vMap[ny][nx];
	}
	return sum;
}

void EraseFlower(int y, int x) {
	vVisited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		vVisited[ny][nx] = 0;
	}
}

// 백트래킹 꽃을 심어본다
void go(int count, int sum) {
	if (count == 3) {
		nMin = min(nMin, sum);
		return;
	}

	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n-1; j++) {
			// 꽃을 심을수 있는가 체크
			if (CheckFlower(i, j)) {
				go(count+1, sum + SetFlower(i, j));
				EraseFlower(i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vMap.assign(n, vector<int>(n, 0));
	vVisited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vMap[i][j];
		}
	}
	go(0, 0);

	cout << nMin;

	return 0;
}