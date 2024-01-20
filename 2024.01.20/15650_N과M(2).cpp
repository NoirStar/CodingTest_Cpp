#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;

	cin >> n >> m;
	vector<bool> vRet(n, false);

	for (int i = 0; i < m; i++) vRet[i] = true;

	do {
		for (int i = 0; i < n; i++) {
			if (vRet[i]) cout << i+1 << ' ';
		}
		cout << '\n';
	} while (prev_permutation(vRet.begin(), vRet.end()));

	return 0;
}