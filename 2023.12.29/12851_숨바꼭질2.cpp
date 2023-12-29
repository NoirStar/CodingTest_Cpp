#include <bits/stdc++.h>

using namespace std;

// 재귀로 했더니 모든경우의 수가 제대로 고려안됨. BFS로 도전
// 가중치가 같나? 그냥 생각하면 아닐수도 있는데 잘생각하면 같음
// 1초에 한번씩 움직이니까. 정점은 x-1, x+1, x*2 이렇게 3개로 볼 수있음.
// n 위치가 visited 로 설정됨

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