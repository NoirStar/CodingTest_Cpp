#include <bits/stdc++.h>

using namespace std;

int main() {
	int nN, nM;
	cin >> nN >> nM;

	vector<vector<int>> vPattern(nN);

	for (int i = 0; i < nN; i++) {
		string strPattern;
		cin >> strPattern;
		for (const auto& pattern : strPattern) {
			int nPattern = pattern == 'W' ? 0 : 1;
			vPattern[i].push_back(nPattern);
		}
	}

	int sum=0;
	set<int> sMin;
	for (int nStartCol = 0; nStartCol < nN - 7; nStartCol++) {
		for (int nStartRow = 0; nStartRow < nM - 7; nStartRow++) {
			int nStartColor = vPattern[nStartCol][nStartRow];
			for (int i = nStartCol; i < nStartCol + 8; i++) {
				for (int j = nStartRow; j < nStartRow + 8; j++) {
					if ((nStartColor != vPattern[i][j])) {
						sum++;
					}
					nStartColor = !nStartColor;
				}
				nStartColor = !nStartColor;
			}
			sMin.insert(sum);
			sum = 0;

			nStartColor = !vPattern[nStartCol][nStartRow];
			for (int i = nStartCol; i < nStartCol + 8; i++) {
				for (int j = nStartRow; j < nStartRow + 8; j++) {
					if ((nStartColor != vPattern[i][j])) {
						sum++;
					}
					nStartColor = !nStartColor;
				}
				nStartColor = !nStartColor;
			}
			sMin.insert(sum);
			sum = 0;
		}
	}
	cout << *sMin.begin();

	return 0;
}