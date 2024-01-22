#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, nFrom, nTo, nRet = 1;
	cin >> n;

	vector<pair<int, int>> vMeet;
	for (int i = 0; i < n; i++) {

		cin >> nFrom >> nTo;
		vMeet.push_back({ nTo, nFrom });
	}

	sort(vMeet.begin(), vMeet.end());
	nFrom = vMeet[0].second;
	nTo = vMeet[0].first;
	for (int i = 1; i < n; i++) {
		if (vMeet[i].second < nTo) continue;
		nFrom = vMeet[i].second;
		nTo = vMeet[i].first;
		nRet++;
	}
	cout << nRet;

	return 0;
}