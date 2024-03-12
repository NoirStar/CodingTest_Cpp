#include <bits/stdc++.h>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, l, time = 0;
	cin >> n >> k;

	vector<vector<int>> vMap(n, vector<int>(n, 0));
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		vMap[y-1][x-1] = 1;
	}
	
	// deque�� �����ϰ�, ����� �Ծ�����
	// ���� ��ġ�� �״�� �ְ�, �� �� �Ӹ��� +1��ǥ  push_front
	deque<pair<int, int>> dqSnake;
	dqSnake.push_back({0,0});

	int nDir = 0;
	vector<pair<int,int>> vTime;

	cin >> l;
	for (int i = 0; i < l; i++) {
		int s;
		char c;
		cin >> s >> c;
		if (c == 'L') {
			nDir--;
			if (nDir < 0) nDir += 4;
		}
		else {
			nDir++;
			if (nDir > 3) nDir -= 4;
		}
		vTime.push_back({s+1, nDir});
	}

	int i, nIdx = 0, d = 0;
	for (i = 1;;i++) {
		if (vTime.size() != nIdx && i == vTime[nIdx].first) {
			d = vTime[nIdx].second;
			nIdx++;
		}
		auto front = dqSnake.front();
		int ny = front.first + dy[d];
		int nx = front.second + dx[d];

		// �Ӹ��� �浹�ߴ���
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			break;
		}

		// ���̶� �浹�ߴ���
		bool bEnd = false;
		for (int j = 1; j < dqSnake.size(); j++) {
			if (dqSnake[j].first == ny && dqSnake[j].second == nx) {
				bEnd = true;
				break;
			}
		}
		if (bEnd) break;

		// �����
		if (vMap[ny][nx] == 1) {
			vMap[ny][nx] = 0;
			dqSnake.push_front({ ny, nx });
		}
		else {
			dqSnake.push_front({ ny, nx });
			dqSnake.pop_back();
		}
	}
	
	cout << i;

	return 0;
}