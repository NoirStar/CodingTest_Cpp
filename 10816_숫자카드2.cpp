#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nCard, nInt;
	cin >> nCard;
	map<int,int> mCard;

	for (int i = 0; i < nCard; i++) {
		int nTemp;
		cin >> nTemp;
		auto it = mCard.find(nTemp);
		if (it == mCard.end()) {
			mCard.insert(make_pair(nTemp, 1));
		}
		else {
			(*it).second++;
		}
	}

	cin >> nInt;
	vector<int> vInt(nInt);

	for (int i = 0; i < nInt; i++) {
		cin >> vInt[i];
	}

	vector<int> vRet;
	for (const auto& i : vInt) {
		auto it = mCard.find(i);
		if (it == mCard.end()) {
			vRet.push_back(0);
		}
		else {
			vRet.push_back((*it).second);
		}
	}

	for (const auto& i : vRet) {
		cout << i << " ";
	}

	return 0;
}