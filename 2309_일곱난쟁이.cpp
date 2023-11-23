#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> vShort(9);
	for (int i = 0; i < 9; i++) {
		cin >> vShort[i];
	}

	vector<bool> vTemp(vShort.size(), false);
	for (int i = 0; i < 7; i++) {
		vTemp[i] = true;
	}

	do {
		int nSum = 0;
		vector<int> vRet;
		for (int i = 0; i < vShort.size(); i++) {
			if (vTemp[i]) {
				nSum += vShort[i];
				vRet.push_back(vShort[i]);
			}
		}
		if (nSum == 100) {
			sort(vRet.begin(), vRet.end());
			for (const auto& r : vRet) {
				cout << r << '\n';
			}
			break;
		}
	} while (prev_permutation(vTemp.begin(), vTemp.end()));

	return 0;
}