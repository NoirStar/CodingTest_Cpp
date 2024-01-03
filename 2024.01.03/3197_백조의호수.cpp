#include <bits/stdc++.h>

using namespace std;

// flood fill 이용한다. queue를 두개를 이용하여 하는게 정석

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, -1, 0, 1 };

const int nMax = 1501;
int n, m;

char vMap[nMax][nMax];
bool vVisitWater[nMax][nMax], vVisitSwan[nMax][nMax];
queue<pair<int, int>> qWater, qWaterTemp, qSwan, qSwanTemp;

void ClearQueue(queue<pair<int, int>>& q) {
	while (!q.empty()) q.pop();
}

bool MoveSwan() {
	int x, y;
	while (qSwan.size()) {
		tie(y, x) = qSwan.front();
		qSwan.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisitSwan[ny][nx]) continue;
			
			vVisitSwan[ny][nx] = 1;
			if (vMap[ny][nx] == 'L') return true;
			else if (vMap[ny][nx] == '.') {
				qSwan.push({ ny,nx });
			}
			else if (vMap[ny][nx] == 'X') {
				qSwanTemp.push({ ny,nx });
			}
		}
	}
	return false;
}

void MoveWater() {
	int x, y;
	while (qWater.size()) {
		tie(y, x) = qWater.front();
		qWater.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || vVisitWater[ny][nx]) continue;

			if (vMap[ny][nx] == 'X') {
				qWaterTemp.push({ny,nx});
				vMap[ny][nx] = '.';
				vVisitWater[ny][nx] = 1;
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int nSwanX, nSwanY;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vMap[i][j];
			if (vMap[i][j] == 'L') {
				nSwanY = i;
				nSwanX = j;
			}
			if (vMap[i][j] == '.' || vMap[i][j] == 'L') {
				qWater.push({ i,j });
				vVisitWater[i][j] = 1;
			}
		}
	}

	qSwan.push({ nSwanY,nSwanX });
	vVisitSwan[nSwanY][nSwanX] = 1;

	int nDays = 0;
	while (true) {
		if (MoveSwan()) break;
		MoveWater();

		qWater = qWaterTemp;
		qSwan = qSwanTemp;
		ClearQueue(qWaterTemp);
		ClearQueue(qSwanTemp);
		nDays++;
	}

	cout << nDays;
	return 0;
}