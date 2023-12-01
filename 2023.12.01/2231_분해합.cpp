#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNum;
	cin >> nNum;

	for (int i = 1; i <= nNum; i++) {
		int nCon = i;
		int nTemp = i;
		while (nTemp > 0) {
			nCon += (nTemp % 10);
			nTemp /= 10;
		}
		if (nCon == nNum) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}