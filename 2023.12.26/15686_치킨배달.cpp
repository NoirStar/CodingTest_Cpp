#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nMap, nChi, nTemp;
	cin >> nMap >> nChi;

	vector<pair<int, int>> vChi, vHouse;
	vector<int> vRet;

	for (int i = 0; i < nMap; i++) {
		for (int j = 0; j < nMap; j++) {
			cin >> nTemp;
			if (nTemp == 2) vChi.push_back({ i, j });
			else if (nTemp == 1) vHouse.push_back({ i, j });
		}
	}

	vector<bool> vCombi(vChi.size(), false);
	for (int i = 0; i < nChi; i++) {
		vCombi[i] = true;
	}

	do {
		int nLen = 0;
		for (int j = 0; j < vHouse.size(); j++) {
			int nLenMin = 1000;
			for (int k = 0; k < vChi.size(); k++) {
				if (vCombi[k]) {
					nLenMin = min(nLenMin, abs(vChi[k].first - vHouse[j].first) +
						abs(vChi[k].second - vHouse[j].second));
				}
			}
			nLen += nLenMin;
		}
		vRet.push_back(nLen);
	
	} while (prev_permutation(vCombi.begin(), vCombi.end()));


	cout << *(min_element(vRet.begin(), vRet.end()));

	return 0;
}