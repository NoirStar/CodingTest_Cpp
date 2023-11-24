#include <bits/stdc++.h>

using namespace std;

int main() {
	string strInput, strOutput;
	getline(cin, strInput);
	for (char& c : strInput) {
		if (c >= 'a' && c <= 'z') {
			if (c + 13 > 'z') {
				c = c + 12 - 'z' + 'a';
			}
			else {
				c += 13;
			}
			strOutput += c;
		}
		else if (c >= 'A' && c <= 'Z') {
			if (c + 13 > 'Z') {
				c = c + 12 - 'Z' + 'A';
			}
			else {
				c += 13;
			}
			strOutput += c;
		}
		else {
			strOutput += c;
		}
	}
	cout << strOutput;

	return 0;
}