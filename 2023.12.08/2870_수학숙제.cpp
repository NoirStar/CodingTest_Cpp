#include <bits/stdc++.h>

using namespace std;

void RemoveZero(string& s) {
	while (true) {
		if (s.size() && s.front() == '0')s.erase(s.begin());
		else break;
	}
	if (s.size() == 0) s = "0";
}

int main() {
	int nTest;
	cin >> nTest;
	
	vector<string> vRet;
	for (int i = 0; i < nTest; i++) {
		string strInput;
		cin >> strInput;
		string ret;
		for (int j = 0; j < strInput.size(); j++) {
			if (strInput[j] < 'A') {
				ret += strInput[j];
			}
			else if (ret.size()) {
				RemoveZero(ret);
				vRet.push_back(ret);
				ret = "";
			}
		}
		if (ret.size()) {
			RemoveZero(ret);
			vRet.push_back(ret);
			ret = "";
		}
	}

	sort(vRet.begin(), vRet.end(), [](const string& s1, const string& s2) {
		if (s1.size() == s2.size()) {
			return s1 < s2;
		}
		return s1.size() < s2.size();
	});

	for (const auto& n : vRet) cout << n << '\n';

	return 0;
}