#include <bits/stdc++.h>

// 왼쪽엔 n개 오른쪽엔 m 
using namespace std;

vector<vector<long long>> g_vMemo;

long long Combination(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	// 기존 값이 있으면 반환
	if (-1 != g_vMemo[n][k]) {
		return g_vMemo[n][k];
	}
	// nCr = n-1Cr-1 + n-1Cr
	g_vMemo[n][k] = Combination(n - 1, k - 1) + Combination(n - 1, k);

	return g_vMemo[n][k];
}


int main() {

	int nInput, nLeft, mRight;
	vector<int> vResult;

	cin >> nInput;

	for (int i = 0; i < nInput; i++) {
		cin >> nLeft >> mRight;
		g_vMemo.assign(mRight + 1, vector<long long>(nLeft + 1, -1));
		vResult.push_back(Combination(mRight, nLeft));
	}

	for (auto result : vResult) {
		cout << result << "\n";
	}

	return 0;
}