#include <bits/stdc++.h>

using namespace std;

int main() {
	int nString, nBrand;
	cin >> nString >> nBrand;
	vector<int> vPackPrice(nBrand), vOnePrice(nBrand);

	for (int i = 0; i < nBrand; i++) {
		cin >> vPackPrice[i] >> vOnePrice[i];
	}

	sort(vPackPrice.begin(), vPackPrice.end());
	sort(vOnePrice.begin(), vOnePrice.end());

	int nMoneySum = 0;
	if ((nString % 6) == 0) {
		if (vPackPrice[0] <= vOnePrice[0] * 6) {
			nMoneySum += vPackPrice[0] * (nString / 6);
		}
		else {
			nMoneySum += vOnePrice[0] * nString;
		}
	}
	else {
		if (vPackPrice[0] <= vOnePrice[0] * 6) {
			if (vPackPrice[0] <= vOnePrice[0] * (nString % 6)) {
				nMoneySum += vPackPrice[0] * ((nString / 6) + 1);
			}
			else {
				nMoneySum += vPackPrice[0] * (nString / 6);
				nMoneySum += vOnePrice[0] * (nString % 6);
			}
		}
		else {
			nMoneySum += vOnePrice[0] * nString;
		}
	}
	cout << nMoneySum;
	return 0;
}