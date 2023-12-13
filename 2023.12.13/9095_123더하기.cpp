#include <bits/stdc++.h>

using namespace std;

// d[n] = d[n-1] + d[n-2] + d[n-3]
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nTest;

	cin >> nTest;

	vector<int> vDp(12,0);
	vDp[1] = 1;
	vDp[2] = 2;
	vDp[3] = 4;
	
	for (int i = 4; i < 11; i++) {
		vDp[i] = vDp[i - 1] + vDp[i - 2] + vDp[i - 3];
	}

	for (int i = 0; i < nTest; i++) {
		int nTemp;
		cin >> nTemp;
		cout << vDp[nTemp] << '\n';
	}


	return 0;
}