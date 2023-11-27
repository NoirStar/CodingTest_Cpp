#include <bits/stdc++.h>

using namespace std;

int main() {
	int nQuiz;
	cin >> nQuiz;
	vector<string> vQuiz(nQuiz);

	for (int i = 0; i < nQuiz; i++) {
		cin >> vQuiz[i];
	}

	for (auto s : vQuiz) {
		int nSum = 0;
		int nO = 0;
		for (auto c : s) {
			if (c == 'O') {
				nSum += ++nO;
			}
			else {
				nO = 0;
			}
		}
		cout << nSum << '\n';
	}
	return 0;
}