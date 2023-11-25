#include <bits/stdc++.h>

using namespace std;

int main() {
	int nTest;
	cin >> nTest;
	vector<string> vRet;

	for (int i = 0; i < nTest; i++) {
		int nRepeat;
		string strRepeat, strRet;
		cin >> nRepeat;
		cin >> strRepeat;

		for (auto s : strRepeat) {
			for (int j = 0; j < nRepeat; j++) {
				strRet += s;
			}
		}
		vRet.push_back(strRet);
	}

	for (auto s : vRet) {
		cout << s << '\n';
	}

	return 0;
}