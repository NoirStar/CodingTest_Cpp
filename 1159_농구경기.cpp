#include <bits/stdc++.h>

using namespace std;

int main() {
	int nSunsu;
	map<char, int> mSunsu;
	cin >> nSunsu;

	for (int i = 0; i < nSunsu; i++) {
		string strTemp;
		cin >> strTemp;

		if (mSunsu[strTemp.front()] == 0) {
			mSunsu[strTemp.front()] = 1;
		}
		else {
			mSunsu[strTemp.front()]++;
		}
	}

	string strRet;
	for (const auto& m : mSunsu) {
		if (m.second > 4) {
			strRet += m.first;
		}
	}

	if (strRet.empty()) strRet = "PREDAJA";
	cout << strRet;

	return 0;
}