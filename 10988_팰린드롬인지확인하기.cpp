#include <bits/stdc++.h>

using namespace std;

int main() {
	string strInput;
	cin >> strInput;
	
	bool bSame = true;
	for (int i = 0; i < strInput.size() / 2; i++) {
		if (strInput[i] != strInput[strInput.size() - 1 - i]) {
			bSame = false;
			break;
		}
	}
	cout << bSame;

	return 0;
}