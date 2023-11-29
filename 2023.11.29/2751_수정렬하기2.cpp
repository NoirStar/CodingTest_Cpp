#include <bits/stdc++.h>

using namespace std;


int main() {
	int nNum;
	cin >> nNum;
	set<int> sNum;

	for (int i = 0; i < nNum; i++) {
		int nTemp;
		cin >> nTemp;
		sNum.insert(nTemp);
	}
	
	for (const auto& n : sNum) cout << n << '\n';
	return 0;
}

