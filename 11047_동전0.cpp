#include <bits/stdc++.h>

using namespace std;

int main() {
	int nN, nK;
	cin >> nN >> nK;
	vector<int> vCoin(nN);

	for (int i = 0; i < nN; i++) {
		cin >> vCoin[i];
	}

	int nCoin = 0;
	int nIdx = vCoin.size() - 1;
	while (nK != 0) {
		if (vCoin[nIdx] > nK) {
			nIdx--;
		}
		else {
			nK -= vCoin[nIdx];
			nCoin++;
		}
	}
	cout << nCoin;
	return 0;
}