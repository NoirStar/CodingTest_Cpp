#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPeople;
	cin >> nPeople;

	vector<int> vTime(nPeople);

	for (int i = 0; i < nPeople; i++) {
		cin >> vTime[i];
	}

	sort(vTime.begin(), vTime.end());

	int nSum = 0;
	for (int i = 0; i < nPeople; i++) {
		int nSumTemp = 0;
		for (int j = 0; j < i + 1; j++) {
			nSumTemp += vTime[j];
		}
		nSum += nSumTemp;
	}
	cout << nSum;

	return 0;
}