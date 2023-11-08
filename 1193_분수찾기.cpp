#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPosition;
	
	cin >> nPosition;

	for (int i = 1;; i++) {
		if (nPosition > i) {
			nPosition -= i;
		} else {
			i % 2 ? cout << i - nPosition + 1 << '/' << nPosition :
				cout << nPosition << '/' << i - nPosition + 1;
			break;
		}
	}
	return 0;
}