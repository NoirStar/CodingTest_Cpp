#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vVisited;
int n, k;

// 50만 X 50만이라서 공간복잡도가 크다.
// 동생이랑 같이가다 만나는경우, 홀짝이 맞을경우.

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int nRet = 0;
	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	int nTurn = 1; // 홀짝을 반복해서 왔다갔다하는 턴 

	// 수빈이의 위치 / 동생의 위치 수빈이의 위치를 대폭축소
	vVisited.assign(2, vector<int>(500001, 0));
	// 처음의 턴은 0이니까 0으로 주는듯 처음위치 방문기록
	vVisited[0][n] = 1;

	queue<int> q;
	q.push(n);

	bool bFind = false;
	while (!q.empty()) {
		// 동생 이동
		k += nTurn;
		if (k > 500000) break;

		// 수빈이의 상태는 두가지뿐 짝수, 홀수 
		// 어떤 지점을 수빈이가 5초에 방문했고, 동생이 7초에 방문한다면 만날 수있음.
		// 턴이 5라면, 5초. 5 % 2 == 1  홀수상태의 수빈이가 방문했다면 만날 수 있음
		if (vVisited[nTurn % 2][k]) {
			bFind = true;
			break;
		}

		// floodfill 알고리즘 - 단계별로 색깔을 칠하는 알고리즘.
		// 원래는 한개씩 빼서 진행하지만 q 사이즈 만큼 진행한다는건 단계(턴)으로 묶어서 진행가능.
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