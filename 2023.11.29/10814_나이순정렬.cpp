#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPeople;
	cin >> nPeople;
	vector<pair<int, string>> vPeople(nPeople);

	for (int i = 0; i < nPeople; i++) {
		int nAge;
		string strName;
		cin >> nAge;
		cin >> strName;
		vPeople[i] = make_pair(nAge, strName);
	}
	stable_sort(vPeople.begin(), vPeople.end(), [](const pair<int, string>& p1, const pair<int, string>& p2) {
		return p1.first < p2.first;
	});
	
	for (const auto& p: vPeople) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}