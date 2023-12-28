#include <bits/stdc++.h>

using namespace std;

// �� BFS�� Ǯ��� �ұ�? 
// ����ġ�� ������ �ִܰŸ����Ҷ��� ������ �˾Ҵµ�
// �� ������ �׷����� ��Ÿ���� �־���Ѵ�. �׷����� ��Ÿ���� ����ġ�� ���� ���������� �̵�
// ü���� 0 �̵Ǵ� ����. �ִܰŸ�. ü���� �� ��ǥ�� �ȴ�
// �������� ny nx�� ���� ����

vector<vector<int>> vDamage = {
	{9,3,1}, {9,1,3},
	{3,9,1}, {3,1,9},
	{1,3,9}, {1,9,3}, 
};
vector<vector<vector<int>>> vVisited;
vector<int> vHealth;
int nMin = 100000;
int nScv;

struct health {
	int a;
	int b;
	int c;
};

void bfs(int a, int b, int c) {
	queue<health> q;
	q.push({ a,b,c });
	vVisited[a][b][c] = 1;
	int nCount = 0;

	while (!q.empty()) {
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = a - vDamage[i][0];
			int nb = b - vDamage[i][1];
			int nc = c - vDamage[i][2];

			if (na < 0) na = 0;
			if (nb < 0) nb = 0;
			if (nc < 0) nc = 0;

			if (na == 0 && nb == 0 && nc == 0) {
				nMin = min(nMin, vVisited[a][b][c] + 1);
				continue;
			}

			if ((na > 0 || nb > 0 || nc > 0) && !vVisited[na][nb][nc]) {
				q.push({ na, nb, nc });
				vVisited[na][nb][nc] = vVisited[a][b][c] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> nScv;
	vHealth.assign(3, 0);
	vVisited.assign(61, vector<vector<int>>(61, vector<int>(61, 0)));
		
	for (int i = 0; i < nScv; i++) {
		cin >> vHealth[i];
	}

	bfs(vHealth[0], vHealth[1], vHealth[2]);

	cout << nMin-1;

	return 0;
}