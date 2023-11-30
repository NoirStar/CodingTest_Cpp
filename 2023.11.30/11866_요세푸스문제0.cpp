#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPeople, nCount;
	cin >> nPeople >> nCount;

	queue<int> qPeople;
	for (int i = 1; i <= nPeople; i++) {
		qPeople.push(i);
	}

	vector<int> vRet;
	while (qPeople.size() > 0) {
		for (int i = 0; i < nCount-1; i++) {
			int nFront = qPeople.front();
			qPeople.pop();
			qPeople.push(nFront);
		}
		vRet.push_back(qPeople.front());
		qPeople.pop();
	}

	cout << '<';
	for (int i = 0; i < nPeople; i++) {
		if (i == nPeople - 1) cout << vRet[i] << ">";
		else cout << vRet[i] << ", ";
	}

	return 0;
}