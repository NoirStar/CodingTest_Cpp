#include <bits/stdc++.h>

using namespace std;

// �ΰ��� ����� ������Ʈ�� ����°�. dfs/bfs�� �̿�

int n,m, nMin = 987654321;
vector<int> vPeople, vVisited, vComp;
vector<vector<int>> vConnect;

// here �� ������ġ, value�� ��Ʈ����ŷ���� ���� ������ ����(1 �̳� 0�̳�)
// return�� ������ ������ ����
pair<int, int> dfs(int here, int value) {
	vVisited[here] = 1;
	// ret �ʱⰪ
	pair<int, int> ret = {1, vPeople[here]};

	// �ʱⰪ���� ����� ���� ���������� �̿��Ͽ� dfs����
	for (int there : vConnect[here]) {
		// Ž���� ������ �湮�߰ų�, �ٸ� �����̸� continue
		if (vComp[there] != value || vVisited[there]) continue;
		pair<int, int> p = dfs(there, value);

		// Ž���� ��尳���� �α����� �����ش�.
		ret.first += p.first;
		ret.second += p.second;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// �������� �α��� ����
	vPeople.assign(n + 1, 0);
	vConnect.assign(n + 1, vector<int>());

	for (int i = 1; i <= n; i++) {
		cin >> vPeople[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			// ����� ����
			int con;
			cin >> con;
			vConnect[i].push_back(con);
			vConnect[con].push_back(i);
		}
	}

	// 0001 ~ 1110 ���� ��Ʈ����ŷ���� �� ������ �и�
	for (int i = 1; i < (1 << n) - 1; i++) {
		vVisited.assign(n + 1, 0);
		vComp.assign(n + 1, 0);
		// dfs ���� �ε���
		int s1 = -1, s2 = -1;
		for (int j = 0; j < n; j++) {
			// ���� 1
			if (i & (1 << j)) {
				vComp[j + 1] = 1;
				s1 = j + 1;
			}
			else {
				s2 = j + 1;
			}
		}
		// 1���� 1�� ��
		pair<int, int> c1 = dfs(s1, 1);
		// 2���� 0�� ��
		pair<int, int> c2 = dfs(s2, 0);
		
		// ������ �� �������ٸ�
		if (c1.first + c2.first == n) {
			nMin = min(nMin, abs(c1.second - c2.second));
		}
	}
	cout << (nMin == 987654321 ? -1 : nMin);

	return 0;
}
