#include <bits/stdc++.h>

using namespace std;

// ��ͷ� �ߴ��� ������� ���� ����� ����ȵ�. BFS�� ����
// ����ġ�� ����? �׳� �����ϸ� �ƴҼ��� �ִµ� �߻����ϸ� ����
// 1�ʿ� �ѹ��� �����̴ϱ�. ������ x-1, x+1, x*2 �̷��� 3���� �� ������.
// n ��ġ�� visited �� ������

vector<int> vVisited, vCount;
int n, k;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << 1;
		return 0;
	}

	vVisited.assign(200001, 0);
	vCount.assign(200001, 0);

	vVisited[n] = 1;
	vCount[n] = 1;

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int there : {now - 1, now + 1, now * 2}) {
			if (0 <= there && there <= 200000) {
				if (!vVisited[there]) {
					q.push(there);
					vVisited[there] = vVisited[now] + 1;
					vCount[there] += vCount[now];
				}
				else if (vVisited[there] == vVisited[now] + 1) {
					vCount[there] += vCount[now];
				}
			}
		}
	}
	
	cout << vVisited[k] - 1 << '\n';
	cout << vCount[k];

	return 0;
}