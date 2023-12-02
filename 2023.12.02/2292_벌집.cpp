#include <bits/stdc++.h>

using namespace std;

int main() {
	int nTest;
	cin >> nTest;

	vector<int> vRet;

	int nCount = 1, nNum = 0;
	while (nTest > nCount) {
		vRet.push_back(nCount);
		nNum++;
		nCount += 6 * nNum;
	}

	cout << vRet.size()+1;

	return 0;
}