#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, nApple;
	cin >> n >> m >> nApple;
	
	int nStart = 1;
	int nEnd = m;
	int nSum = 0;


	for (int i = 0; i < nApple; i++) {
		int nPos;
		cin >> nPos;
		if (nPos > nEnd) {
			nSum += (nPos - nEnd);
			nStart += nPos - nEnd;
			nEnd = nStart + m - 1;
		}
		else if (nPos < nStart) {
			nSum += (nStart - nPos);
			nStart -= nStart - nPos;
			nEnd = nStart + m - 1;
		} 
	}
	cout << nSum;
	return 0;
}