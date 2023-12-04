#include <bits/stdc++.h>

using namespace std;

int main() {
	int nA, nB, nV;
	cin >> nA >> nB >> nV;

	int nRet = ceil((nV - nA) / (floor)(nA - nB)) + 1;
	cout << nRet;
	return 0;
}