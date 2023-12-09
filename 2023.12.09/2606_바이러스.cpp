#include <bits/stdc++.h>

using namespace std;

int nCom, nSun,nCount = 0;
vector<vector<int>> vCom;
vector<bool> vVisited;

void dfs(int here) {
	nCount++;
	vVisited[here] = true;
	for (int there : vCom[here]) {
		if (vVisited[there]) continue;
		dfs(there);
	}
}

int main() {

	cin >> nCom >> nSun;
	
	vCom.assign(104,vector<int>());
	vVisited.assign(104, 0);

	for (int i = 0; i < nSun; i++) {
		int here, there;
		cin >> here >> there;
		vCom[here].push_back(there);
		vCom[there].push_back(here);
	}
	dfs(1);
	cout << nCount-1;

	return 0;
}