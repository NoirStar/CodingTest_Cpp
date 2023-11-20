#include <bits/stdc++.h>

using namespace std;

int main() {
	int nMoney;
	cin >> nMoney;
	stack<int> sMoney;

	for (int i = 0; i < nMoney; i++) {
		int nTemp;
		cin >> nTemp;
		if (nTemp == 0) {
			sMoney.pop();
		}
		else {
			sMoney.push(nTemp);
		}
	}
	
	int nSum = 0;
	while (!sMoney.empty()) {
		nSum += sMoney.top();
		sMoney.pop();
	}
	cout << nSum;


	return 0;
}