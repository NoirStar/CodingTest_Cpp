#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPeople, nJimin, nHansu;
	cin >> nPeople >> nJimin >> nHansu;

	int nRound = 0;
	for (int i = 1; i < nPeople; i *= 2) {
		nRound++;
		nJimin = (nJimin % 2) ? (nJimin + 1) / 2 : nJimin / 2;
		nHansu = (nHansu % 2) ? (nHansu + 1) / 2 : nHansu / 2;

		if (nJimin == nHansu) break;
	}
	cout << nRound;

	return 0;
}