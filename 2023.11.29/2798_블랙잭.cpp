#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCard, nBlackJack;
	cin >> nCard >> nBlackJack;
	vector<int> vCard(nCard);

	for (int i = 0; i < nCard; i++) {
		cin >> vCard[i];
	}
	sort(vCard.begin(), vCard.end());

	int nRet = 0;
	vector<bool> vCombi(nCard, false);
	for (int i = 0; i < 3; i++) {
		vCombi[i] = true;
	}

	do {
		int nSum = 0;
		for (int i = 0; i < nCard; i++) {
			if (vCombi[i] == true) {
				nSum += vCard[i];
			}
		}
		if (nSum >= nRet && nSum <= nBlackJack) {
			nRet = nSum;
		}
	} while (prev_permutation(vCombi.begin(), vCombi.end()));

	cout << nRet;

	
	return 0;
}

