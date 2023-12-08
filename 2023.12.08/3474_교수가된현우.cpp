#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nTest;
	cin >> nTest;

	for (int i = 0; i < nTest; i++) {
		int nPac;
		cin >> nPac;

		int nCount = 0;
		for (int j = 5; j <= nPac; j *= 5) {
			nCount += nPac / j;
		}
		cout << nCount << '\n';
	}

	return 0;
}