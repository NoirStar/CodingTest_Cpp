#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g_vCombi;

int Combination(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}

	if (g_vCombi[n][k] != -1) {
		return g_vCombi[n][k];
	}
	return Combination(n - 1, k) + Combination(n - 1, k - 1);
}

int main() {
	int nN, nK;
	cin >> nN >> nK;
	g_vCombi.assign(nN+1, vector<int>(nK+1, -1));
	cout << Combination(nN, nK);

	return 0;
}