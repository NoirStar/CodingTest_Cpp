#include <bits/stdc++.h>

using namespace std;

int main() {
	string strInput;
	string strAlphabet = "abcdefghijklmnopqrstuvwxyz";
	cin >> strInput;
	for (const auto& s : strAlphabet) {
		auto nPos = strInput.find(s);
		if (nPos != string::npos) {
			cout << nPos << ' ';
		}
		else {
			cout << -1 << ' ';
		}
	} 
	return 0;
}