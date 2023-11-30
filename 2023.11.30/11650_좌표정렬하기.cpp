#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCount;
	cin >> nCount;
	vector<pair<int, int>> vPos(nCount);

	for (int i = 0; i < nCount; i++) {
		int nX, nY;
		cin >> nX >> nY;
		vPos[i] = make_pair(nX, nY);
	}
	sort(vPos.begin(), vPos.end(),
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		if (p1.first == p2.first) {
			return p1.second < p2.second;
		}
		else {
			return p1.first < p2.first;
		}
	});

	for (const auto& p : vPos) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}