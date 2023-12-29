#include <bits/stdc++.h>

using namespace std;

vector<int> vVisited;
vector<int> vPrev;
int n, k;

// �ִܰŸ� BFS, ��ǥ���ƴ� x-1, x+1, x*2 �� �� ���������� �̵�
// ��θ� trace �ϴ� ��� prev �迭�� �ذ��Ѵ�.
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int nRet = 0;
	cin >> n >> k;
	
	vVisited.assign(200004, 0);
	vPrev.assign(200004, 0);
	vVisited[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == k) {
			nRet = vVisited[k];
			break;
		}

		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= 200004) {
				if (!vVisited[next]) {
					q.push(next);
					vVisited[next] = vVisited[now] + 1;
					vPrev[next] = now;
				}
			}
		}
	}

	vector<int> vRet;
	for (int i = k; i != n; i = vPrev[i]) {
		vRet.push_back(i);
	}
	vRet.push_back(n);
	reverse(vRet.begin(), vRet.end());

	cout << nRet - 1 << '\n';
	for (const auto& r : vRet) {
		cout << r << ' ';
	}

	return 0;
}