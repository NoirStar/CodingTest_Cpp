#include <bits/stdc++.h>

using namespace std;

int main() {
	int nNoHear, nNoSee;
	cin >> nNoHear >> nNoSee;

	map<string, int> mNoHearSee;
	for (int i = 0; i < nNoHear; i++) {
		string strInput;
		cin >> strInput;
		mNoHearSee[strInput] = 1;
	}

	int nNoHearSee = 0;
	vector<string> vNoHearSee;
	for (int i = 0; i < nNoSee; i++) {
		string strInput;
		cin >> strInput;
		if (mNoHearSee[strInput] == 1) {
			nNoHearSee++;
			vNoHearSee.push_back(strInput);
		}
	}
	sort(vNoHearSee.begin(), vNoHearSee.end());
	cout << nNoHearSee << '\n';
	for (const auto& str : vNoHearSee) {
		cout << str << '\n';
	}

	return 0;
}