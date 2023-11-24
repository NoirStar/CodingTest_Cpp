#include <bits/stdc++.h>

using namespace std;

int main() {
	int nA, nB, nC, nBefore, nAfter;
	cin >> nA >> nB >> nC;
	vector<int> vInt(100, 0);
	for (int i = 0; i < 3; i++) {
		cin >> nBefore >> nAfter;
		for (int j = nBefore; j < nAfter; j++) {
			vInt[j]++;
		}
	}
	int nSum = 0;
	for (const auto& i : vInt) {
		if (i) {
			if (i == 1) nSum += nA;
			else if (i == 2) nSum += nB * 2;
			else if (i == 3) nSum += nC * 3;
		}
	}
	cout << nSum << "\n";
	return 0;
}