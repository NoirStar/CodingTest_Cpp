#include <bits/stdc++.h>

using namespace std;

// 두개의 연결된 컴포넌트로 만드는것. dfs/bfs를 이용

int n,m, nMin = 987654321;
vector<int> vPeople, vVisited, vComp;
vector<vector<int>> vConnect;

// here 은 시작위치, value는 비트마스킹으로 나눈 영역의 영역(1 이냐 0이냐)
// return은 각구역 노드들의 개수
pair<int, int> dfs(int here, int value) {
	vVisited[here] = 1;
	// ret 초기값
	pair<int, int> ret = {1, vPeople[here]};

	// 초기값으로 양방향 간선 연결정보를 이용하여 dfs시작
	for (int there : vConnect[here]) {
		// 탐색할 지역이 방문했거나, 다른 영역이면 continue
		if (vComp[there] != value || vVisited[there]) continue;
		pair<int, int> p = dfs(there, value);

		// 탐색한 노드개수와 인구수를 더해준다.
		ret.first += p.first;
		ret.second += p.second;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// 각구역의 인구수 벡터
	vPeople.assign(n + 1, 0);
	vConnect.assign(n + 1, vector<int>());

	for (int i = 1; i <= n; i++) {
		cin >> vPeople[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			// 양방향 간선
			int con;
			cin >> con;
			vConnect[i].push_back(con);
			vConnect[con].push_back(i);
		}
	}

	// 0001 ~ 1110 까지 비트마스킹으로 두 영역을 분리
	for (int i = 1; i < (1 << n) - 1; i++) {
		vVisited.assign(n + 1, 0);
		vComp.assign(n + 1, 0);
		// dfs 시작 인덱스
		int s1 = -1, s2 = -1;
		for (int j = 0; j < n; j++) {
			// 영역 1
			if (i & (1 << j)) {
				vComp[j + 1] = 1;
				s1 = j + 1;
			}
			else {
				s2 = j + 1;
			}
		}
		// 1구역 1의 값
		pair<int, int> c1 = dfs(s1, 1);
		// 2구역 0의 값
		pair<int, int> c2 = dfs(s2, 0);
		
		// 구역을 잘 나누었다면
		if (c1.first + c2.first == n) {
			nMin = min(nMin, abs(c1.second - c2.second));
		}
	}
	cout << (nMin == 987654321 ? -1 : nMin);

	return 0;
}
