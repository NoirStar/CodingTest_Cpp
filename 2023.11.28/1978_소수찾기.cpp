#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNumCount, nNum;
	cin >> nNumCount;

	int nCount = 0;
	for (int i = 0; i < nNumCount; i++) {
		bool bIsPrime = true;
		cin >> nNum;
		
		if (nNum == 1) bIsPrime = false;
		for (int j = 2; j * j <= nNum; j++) {
			if (nNum % j == 0) {
				bIsPrime = false;
				break;
			}
		};
		if (bIsPrime) nCount++;
	}
	cout << nCount;
	return 0;
}