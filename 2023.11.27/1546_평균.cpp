#include <bits/stdc++.h>

using namespace std;

int main() {
	int nScore;
	cin >> nScore;
	vector<int> vScore(nScore);

	for (int i = 0; i < nScore; i++) {
		cin >> vScore[i];
	}

	int nMax = *max_element(vScore.begin(), vScore.end());

	float nNewAv = 0;
	for (const auto i : vScore) {
		nNewAv += (float)i / nMax * 100;
	}
	
	cout << nNewAv / nScore;

	return 0;
}