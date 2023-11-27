#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> vRet;
	for (;;) {
		string strInput, strTemp;
		cin >> strInput;

		strTemp = strInput;
		if (strInput == "0") {
			break;
		}
		reverse(strTemp.begin(), strTemp.end());
		if (strInput == strTemp) {
			vRet.push_back("yes");
		}
		else {
			vRet.push_back("no");
		}
	}
	for (const auto& s : vRet) cout << s << '\n';

	return 0;
}