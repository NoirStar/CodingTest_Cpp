#include <bits/stdc++.h>

using namespace std;

template<typename Number, int kBase>
class StaticTime {
public:
	const int kConst = kBase;

	template<typename Sign>
	class Base {
	public:
		static void Parse() {
			Sign::Check();
			Sign::Increment();
		}
	};

	class Positive : public Base<Positive> {

	};

	class Negative : public Base<Negative> {

	};
	

};

int n, m, aMap[10][10], temp[10][10], nRet = 987654321;
vector<pair<int, int>> v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// v가 cctv 위치를 저장하는 함수.
// 선택한 CCTV의 방향에 따라 감시 영역을 확장하고, 변경된 영역의 위치를 반환합니다. 
vector<pair<int, int>> extendCCTV(int here, int dir) {
	vector<pair<int, int>> change;
	int y = v[here].first;
	int x = v[here].second;

	// CCTV가 관찰하는 영역을 설정한다.
	switch (aMap[y][x]) {
	case 1:
		while (true) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
				if (aMap[ny][nx] == 0) {
					// 8로 임의 지정 
					aMap[ny][nx] = 8;
					// dfs를 위해 바뀐 칸들을 저장해서 다시 0으로 되돌리기 위함(상태관리)
					change.push_back({ ny,nx });
				}
				// 일자로 쭉 벽을만날때까지 바꿔야해서 
				y = ny;
				x = nx;
			}
			else break;
		}
		break;
	case 2:
		// 180도 2개
		for (int i = 0; i <= 2; i += 2) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
					if (aMap[ny][nx] == 0) {
						aMap[ny][nx] = 8;
						change.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
		break;
	case 3:
		// 90도 2개
		for (int i = 0; i < 2; i++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
					if (aMap[ny][nx] == 0) {
						aMap[ny][nx] = 8;
						change.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
		break;
	case 4:
		// 3방향
		for (int i = 0; i < 3; i++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
					if (aMap[ny][nx] == 0) {
						aMap[ny][nx] = 8;
						change.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
		break;
	case 5:
		// 4방향
		for (int i = 0; i < 4; i++) {
			int _y = y;
			int _x = x;
			while (true) {
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
					if (aMap[ny][nx] == 0) {
						aMap[ny][nx] = 8;
						change.push_back({ ny,nx });
					}
					_y = ny;
					_x = nx;
				}
				else break;
			}
		}
		break;
	}
	return change;
}

void dfs(int here) {
	if (here == v.size()) {
		int cnt = 0;
		// 사각지대의 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (aMap[i][j] == 0) cnt++;
			}
		}
		nRet = min(nRet, cnt);
		return;
	}

	// 4방향으로의 회전
	for (int k = 0; k < 4; k++) {
		vector<pair<int, int>> change = extendCCTV(here, k);
		dfs(here + 1);
		for (auto c : change) {
			// 다시 원복
			aMap[c.first][c.second] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 1번 한쪽 2번 반대방향 양쪽 3번 90도 양쪽 4번 3방향 5번 4방향

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> aMap[i][j];
			// CCTV위치 저장
			if (aMap[i][j] != 6 && aMap[i][j] != 0) v.push_back({ i,j });
		}
	}

	dfs(0);
	cout << nRet;
	
	return 0;
}