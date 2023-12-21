#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGraph;
vector<bool> vVisited;

void dfs(int here, int dest) {

	for (auto there : vGraph[here]) {
		if (!vVisited[there]) {
			vVisited[there] = true;
			dfs(there, dest);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nNum;
	cin >> nNum;

	vGraph.assign(nNum, vector<int>());

	for (int i = 0; i < nNum; i++) {
		for (int j = 0; j < nNum; j++) {
			int nTemp;
			cin >> nTemp;
			if (nTemp) {
				vGraph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < nNum; i++) {
		for (int j = 0; j < nNum; j++) {
			vVisited.assign(nNum, 0);
			// i 에서 j 까지 
			dfs(i, j);
			cout << vVisited[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}