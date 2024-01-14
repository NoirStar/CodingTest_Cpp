#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	vector<pair<int, int>> vJum;
	for (int i = 0; i < 8; i++) {
		int n;
		cin >> n;
		vJum.push_back({ n, i + 1 });
	}
	sort(vJum.begin(), vJum.end(), [](pair<int, int> p1, pair<int, int> p2) {
		return p1.first > p2.first;
	});

	int nSum = 0;
	vector<int> vRet;
	for (int i = 0; i < 5; i++) {
		nSum += vJum[i].first;
		vRet.push_back(vJum[i].second);
	}

	sort(vRet.begin(), vRet.end());

	cout << nSum << '\n';
	for (int i = 0; i < 5; i++) {
		cout << vRet[i] << ' ';
	}

	return 0;
}