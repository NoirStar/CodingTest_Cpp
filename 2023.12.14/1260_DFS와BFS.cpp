#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vGraph;
vector<bool> vVisited;

void dfs(int here) {
	vVisited[here] = true;

	cout << here << ' ';

	sort(vGraph[here].begin(), vGraph[here].end());
	for (const int& there : vGraph[here]) {
		if (vVisited[there]) continue;
		dfs(there);
	}
}

void bfs(int here) {
	queue<int> q;
	q.push(here);
	vVisited[here] = true;

	while (!q.empty()) {
		int nHere = q.front();
		q.pop();
		
		cout << nHere << ' ';
		sort(vGraph[nHere].begin(), vGraph[nHere].end());
		for (const int& there : vGraph[nHere]) {
			if (vVisited[there]) continue;
			q.push(there);
			vVisited[there] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nJung, nGan, nStart;

	cin >> nJung >> nGan >> nStart;

	vGraph.assign(nJung + 1, vector<int>());

	for (int i = 0; i < nGan; i++) {
		int here, there;
		cin >> here >> there;
		vGraph[here].push_back(there);
		vGraph[there].push_back(here);
	}
	
	vVisited.assign(nJung + 1,0);
	dfs(nStart);

	cout << '\n';

	vVisited.assign(nJung + 1, 0);
	bfs(nStart);

	return 0;
}