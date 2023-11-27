#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCount, nH, nW, nN;
	vector<pair<int, int>> vRoom;
	cin >> nCount;
	for (int i = 0; i < nCount; i++) {
		cin >> nH >> nW >> nN;
		if (nN < nH) {
			vRoom.push_back(make_pair(nN,1));
		}
		else {
			int nHTmp = nN % nH;
			int nWTmp = nN / nH;
			nWTmp = nHTmp == 0 ? nWTmp : nWTmp + 1;
			nHTmp = nHTmp == 0 ? nH : nHTmp;
			vRoom.push_back(make_pair(nHTmp, nWTmp));
		}
	}
	
	for (const auto& r : vRoom) {
		cout << r.first << setw(2) << setfill('0') << r.second << '\n';
	}

	return 0;
}