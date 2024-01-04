#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int nMin = numeric_limits<int>::max();
vector<vector<int>> vMap;
vector<vector<int>> vVisited;

bool CheckLadder() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for(int j = 1; j <= h; j++) {
			// 한칸씩 내려가보기, 현재가 1이라는뜻은 오른쪽 이동, 왼쪽이 1이라는뜻은 왼쪽이동
			if (vVisited[j][start] == 1) start++;
			else if (vVisited[j][start - 1] == 1) start--;
		}
		if (start != i)return false;
	}
	return true;
}

void go(int here, int count) {
	if (count > 3 || count >= nMin) return;
	if (CheckLadder()) {
		nMin = min(nMin, count);
		return;
	}
	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			// 아래로 한칸씩 가면서 완탐/백트래킹
			if (vVisited[i][j] || vVisited[i][j - 1] || vVisited[i][j + 1]) continue;
			vVisited[i][j] = 1;
			go(i, count + 1);
			vVisited[i][j] = 0;
		}
	}



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// n 세로선 m 가로선 h 놓을수 있는가로선 개수
	// h가 y, n이 x
	cin >> n >> m >> h;
	
	vMap.assign(h+4, vector<int>(n+4, 0));
	vVisited.assign(h+4, vector<int>(n+4, 0));

	// 가로선의 정보는 a, b로 나타내는데,  
	// 만약 (1,1) 이라면 y가 1이고, x가 1 (1,1)을 갈수있는곳으로 설정
	// 평소에는 위에서 아래로만 갈수있음

	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		vVisited[y][x] = 1;
	}

	go(1, 0);
	
	if (nMin > 3) {
		cout << -1;
	}
	else cout << nMin;
	
	return 0;
}