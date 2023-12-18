#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nTest, nNum;
	cin >> nTest;

	vector<long long> vDp(101, 0);

	vDp[1] = 1;
	vDp[2] = 1;
	vDp[3] = 1;
	vDp[4] = 2;
	vDp[5] = 2;

	for (int i = 5; i <= 100; i++) {
		vDp[i] = vDp[i - 1] + vDp[i - 5];
	}

	for (int i = 0; i < nTest; i++) {
		cin >> nNum;
		cout << vDp[nNum] << '\n';
	}


	return 0;
}