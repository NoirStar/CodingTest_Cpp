#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNumN, nNumM;

	cin >> nNumN;
	map<int, int> mNumN;
	for (int i = 0; i < nNumN; i++) {
		int nTemp;
		cin >> nTemp;
		mNumN.insert(make_pair(nTemp, i));
	}
	
	cin >> nNumM;
	vector<int> vNumM(nNumM);
	for (int i = 0; i < nNumM; i++) {
		cin >> vNumM[i];
	}

	for (const auto& n : vNumM) {
		if (mNumN.find(n) != mNumN.end()) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
		
	}

	return 0;
}