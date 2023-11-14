#include <bits/stdc++.h>

using namespace std;

int main() {
	int nArray;
	cin >> nArray;

	vector<int> vArrayA(nArray), vArrayB(nArray);

	for (int i = 0; i < nArray; i++) {
		cin >> vArrayA[i];
	}

	for (int i = 0; i < nArray; i++) {
		cin >> vArrayB[i];
	}

	sort(vArrayA.begin(), vArrayA.end());
	sort(vArrayB.begin(), vArrayB.end(), greater<>());
	
	int nSum = 0;
	for (int i = 0; i < nArray; i++) {
		nSum += vArrayA[i] * vArrayB[i];
	}
	cout << nSum;

	return 0;
}