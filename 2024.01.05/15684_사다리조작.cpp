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
			// ��ĭ�� ����������, ���簡 1�̶�¶��� ������ �̵�, ������ 1�̶�¶��� �����̵�
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
			// �Ʒ��� ��ĭ�� ���鼭 ��Ž/��Ʈ��ŷ
			if (vVisited[i][j] || vVisited[i][j - 1] || vVisited[i][j + 1]) continue;
			vVisited[i][j] = 1;
			go(i, count + 1);
			vVisited[i][j] = 0;
		}
	}



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// n ���μ� m ���μ� h ������ �ִ°��μ� ����
	// h�� y, n�� x
	cin >> n >> m >> h;
	
	vMap.assign(h+4, vector<int>(n+4, 0));
	vVisited.assign(h+4, vector<int>(n+4, 0));

	// ���μ��� ������ a, b�� ��Ÿ���µ�,  
	// ���� (1,1) �̶�� y�� 1�̰�, x�� 1 (1,1)�� �����ִ°����� ����
	// ��ҿ��� ������ �Ʒ��θ� ��������

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