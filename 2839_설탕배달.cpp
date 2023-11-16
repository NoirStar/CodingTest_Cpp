#include <bits/stdc++.h>

using namespace std;

int main() {
	int nWeight;
	cin >> nWeight;

	int nCount = -1;
	int nTempWeight = nWeight;
	for (int i = 0; i <= nWeight / 5; i++) {
		int nTempWeight = nWeight;
		nTempWeight -= i * 5;
		for (int j = 0; j <= (nWeight-i*5) / 3; j++) {
			if ((nTempWeight - j * 3) == 0) {
				nCount = i + j;
				break;
			}
			else if((nTempWeight - j * 3) < 0) {
				nCount = -1;
			}
		}
	}
	cout << nCount;

	return 0;
}