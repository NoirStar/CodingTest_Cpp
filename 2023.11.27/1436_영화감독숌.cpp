#include <bits/stdc++.h>

using namespace std;

int main() {
	int nMovie;
	cin >> nMovie;
	
	int nCount, nCountMovie = 0;
	for (nCount = 666; nCountMovie != nMovie; nCount++) {
		int nTemp = nCount;
		while (nTemp > 100) {
			if (nTemp % 1000 == 666) {
				nCountMovie++;
				break;
			}
			nTemp /= 10;
		}
	}
	cout << nCount-1;
	return 0;
}