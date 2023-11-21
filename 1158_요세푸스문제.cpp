#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNp, nKp;
	cin >> nNp >> nKp;

	vector<int> vYose(nNp);
	vector<int> vRet;
	for (int i = 0; i < nNp; i++) {
		vYose[i] = i + 1;
	}

	int nIdx = nKp-1;
	while (vYose.size() > 1) {
		if (nIdx > vYose.size() - 1) {
			nIdx = nIdx % vYose.size(); 
		}
		vRet.push_back(vYose[nIdx]);
		vYose.erase(vYose.begin() + nIdx);
		nIdx += (nKp-1);
	}
	vRet.push_back(*vYose.begin());

	cout << '<';
	for (int i = 0; i < nNp-1;i++) {
		cout << vRet[i] << ", ";
	}
	cout << vRet[nNp-1] << '>';
	

	return 0;
}