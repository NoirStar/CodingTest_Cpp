#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vAdj(51);
int nRoot, nDelete;

int dfs(int p) {
	int nRet = 0;
	int nChild = 0;

	for (int c : vAdj[p]) {
		if (c == nDelete) continue;
		nRet += dfs(c);
		nChild++;
	}
	if (nChild == 0) return 1;
	return nRet;
}

int main() {
	int nNode;
	cin >> nNode;

	for (int i = 0; i < nNode; i++) {
		int nParent;
		cin >> nParent;
		if (nParent == -1) {
			nRoot = i;
		}
		else {
			vAdj[nParent].push_back(i);
		}
	}

	cin >> nDelete;

	if (nDelete == nRoot) {
		cout << 0 << '\n';
		return 0;
	}
	cout << dfs(nRoot) << '\n';

	return 0;
}