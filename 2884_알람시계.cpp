#include <bits/stdc++.h>

using namespace std;

int main() {
	int nMin, nHour;
	cin >> nHour >> nMin;

	if (nMin - 45 < 0) {
		nMin = nMin - 45 + 60;
		if (nHour == 0) {
			nHour = 23;
		}
		else {
			nHour--;
		}
	}
	else {
		nMin -= 45;
	}
	cout << nHour << ' ' << nMin;

	return 0;
}