#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nPos;
	cin >> nPos;
	vector<pair<int, int>> vPos(nPos);

	for (int i = 0; i < nPos; i++) {
		int nX, nY;
		cin >> nX >> nY;
		vPos[i] = make_pair(nX, nY);
	}

	sort(vPos.begin(), vPos.end(), 
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	});
	
	for (const auto& p : vPos) {
		cout << p.first << ' ' << p.second << '\n';
	}


	return 0;
}