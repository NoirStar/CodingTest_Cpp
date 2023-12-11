#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vRelative;
vector<bool> vVisited;

int dfs(int here) {
	vVisited[here] = true;
	int nCount = 1;

	for (const auto& there : vRelative[here]) {
		if (vVisited[there]) continue;
		nCount += dfs(there);
	}
	return nCount;
}

int main() {
	int nCom, nCase;
	cin >> nCom >> nCase;

	vRelative.assign(nCom + 1, vector<int>());

	// a가 b를 신뢰하는 관계면 b를 해킹하면 a도 가장 많은 경로? 를 가진 컴퓨터를 찾으면된다.
	for (int i = 0; i < nCase; i++) {
		int a, b;
		cin >> b >> a;
		vRelative[a].push_back(b);
	}

	map<int, int> mRet;
	int nMax = 0;
	for (int i = 1; i <= nCom; i++) {
		vVisited.assign(nCom + 1, 0);
		int nTemp = dfs(i);
		nMax = max(nMax, nTemp);
		mRet[i] = nTemp;
	}

	for (const auto& r : mRet) {
		if (nMax == r.second) cout << r.first << ' ';
	}


	return 0;
}