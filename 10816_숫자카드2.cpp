#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCard, nInt;
	cin >> nCard;
	map<int,int> mCard;

	for (int i = 0; i < nCard; i++) {
		int nTemp;
		cin >> nTemp;
		if (mCard[nTemp] == 0) {
			mCard[nTemp] = 1;
		}
		else {
			mCard[nTemp] += 1;
		}
	}

	cin >> nInt;
	vector<int> vInt(nInt);

	for (int i = 0; i < nInt; i++) {
		cin >> vInt[i];
	}
	
	for (const auto& i : vInt) {
		cout << mCard[i] << ' ';
	}

	return 0;
}