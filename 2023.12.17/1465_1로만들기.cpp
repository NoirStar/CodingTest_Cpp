#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nMin;

	cin >> nMin;
	vector<int> vDp(1000000);

	for (int i = 2; i <= nMin; i++) {

		vDp[i] = vDp[i - 1] + 1;

		if (i % 2 == 0) {
			vDp[i] = min(vDp[i], vDp[i / 2] + 1);
		}

		if (i % 3 == 0) {
			vDp[i] = min(vDp[i], vDp[i / 3] + 1);
		}
	}

	cout << vDp[nMin];

	return 0;
}