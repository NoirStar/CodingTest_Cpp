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

// v�� cctv ��ġ�� �����ϴ� �Լ�.
// ������ CCTV�� ���⿡ ���� ���� ������ Ȯ���ϰ�, ����� ������ ��ġ�� ��ȯ�մϴ�. 
vector<pair<int, int>> extendCCTV(int here, int dir) {
	vector<pair<int, int>> change;
	int y = v[here].first;
	int x = v[here].second;

	// CCTV�� �����ϴ� ������ �����Ѵ�.
	switch (aMap[y][x]) {
	case 1:
		while (true) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m && aMap[ny][nx] != 6) {
				if (aMap[ny][nx] == 0) {
					// 8�� ���� ���� 
					aMap[ny][nx] = 8;
					// dfs�� ���� �ٲ� ĭ���� �����ؼ� �ٽ� 0���� �ǵ����� ����(���°���)
					change.push_back({ ny,nx });
				}
				// ���ڷ� �� �������������� �ٲ���ؼ� 
				y = ny;
				x = nx;
			}
			else break;
		}
		break;
	case 2:
		// 180�� 2��
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
		// 90�� 2��
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
		// 3����
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
		// 4����
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
		// �簢������ ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (aMap[i][j] == 0) cnt++;
			}
		}
		nRet = min(nRet, cnt);
		return;
	}

	// 4���������� ȸ��
	for (int k = 0; k < 4; k++) {
		vector<pair<int, int>> change = extendCCTV(here, k);
		dfs(here + 1);
		for (auto c : change) {
			// �ٽ� ����
			aMap[c.first][c.second] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 1�� ���� 2�� �ݴ���� ���� 3�� 90�� ���� 4�� 3���� 5�� 4����

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> aMap[i][j];
			// CCTV��ġ ����
			if (aMap[i][j] != 6 && aMap[i][j] != 0) v.push_back({ i,j });
		}
	}

	dfs(0);
	cout << nRet;
	
	return 0;
}