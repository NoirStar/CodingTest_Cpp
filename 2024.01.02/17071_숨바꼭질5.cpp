#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vVisited;
int n, k;

// 50�� X 50���̶� �������⵵�� ũ��.
// �����̶� ���̰��� �����°��, Ȧ¦�� �������.

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int nRet = 0;
	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	int nTurn = 1; // Ȧ¦�� �ݺ��ؼ� �Դٰ����ϴ� �� 

	// �������� ��ġ / ������ ��ġ �������� ��ġ�� �������
	vVisited.assign(2, vector<int>(500001, 0));
	// ó���� ���� 0�̴ϱ� 0���� �ִµ� ó����ġ �湮���
	vVisited[0][n] = 1;

	queue<int> q;
	q.push(n);

	bool bFind = false;
	while (!q.empty()) {
		// ���� �̵�
		k += nTurn;
		if (k > 500000) break;

		// �������� ���´� �ΰ����� ¦��, Ȧ�� 
		// � ������ �����̰� 5�ʿ� �湮�߰�, ������ 7�ʿ� �湮�Ѵٸ� ���� ������.
		// ���� 5���, 5��. 5 % 2 == 1  Ȧ�������� �����̰� �湮�ߴٸ� ���� �� ����
		if (vVisited[nTurn % 2][k]) {
			bFind = true;
			break;
		}

		// floodfill �˰��� - �ܰ躰�� ������ ĥ�ϴ� �˰���.
		// ������ �Ѱ��� ���� ���������� q ������ ��ŭ �����Ѵٴ°� �ܰ�(��)���� ��� ���డ��.
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int now = q.front();
			q.pop();
			for (int next : {now - 1, now + 1, now * 2}) {
				if (next < 0 || next > 500000 || vVisited[nTurn % 2][next]) continue;

				vVisited[nTurn % 2][next] = vVisited[(nTurn + 1) % 2][now];

				if (next == k) {
					bFind = true;
					break;
				}
				q.push(next);
			}
			if (bFind) break;
		}
		if (bFind) break;
		nTurn++;
	}

	if (bFind) cout << nTurn;
	else cout << -1;

	return 0;
}