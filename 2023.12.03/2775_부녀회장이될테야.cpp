#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g_vPeople;

int GetPeople(int k, int n) {
	if (n == 1) return 1;
	if (k == 0) return n;

	if (g_vPeople[k][n] != 0) return g_vPeople[k][n];

	// 1ÃþÀÇ 2È£´Â  1-1ÃþÀÇ 2È£ + 1ÃþÀÇ 2-1È£
	return GetPeople(k - 1, n) + GetPeople(k, n - 1);
}

int main() {
	int nTest,  nN, nK;
	cin >> nTest;
	vector<int> vRet;
	
	for (int i = 0; i < nTest; i++) {
		cin >> nK >> nN;

		g_vPeople.assign(nK + 1, vector<int>(nN+1, 0));
		vRet.push_back(GetPeople(nK, nN));
	}

	for (const auto& r : vRet) {
		cout << r << '\n';
	}

	return 0;
}