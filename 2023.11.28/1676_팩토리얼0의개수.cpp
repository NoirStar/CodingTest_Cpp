#include <bits/stdc++.h>

using namespace std;

int main() {
	int nFactorial, nNum = 1, nZero = 0;
	cin >> nFactorial;

	for (int i = nFactorial; i >= 2; i--) {
		int nTemp = i;
		while(nTemp % 5 == 0) {
			nZero++;
			nTemp /= 5;
		}
	}
	cout << nZero;
	return 0;
}

