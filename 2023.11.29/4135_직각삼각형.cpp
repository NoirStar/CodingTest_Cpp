#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<string> vRet;
	for (;;) {
		vector<int> vTri(3);
		cin >> vTri[0] >> vTri[1] >> vTri[2];
		sort(vTri.begin(), vTri.end());
		
		if(vTri[0] == 0) break;
		if (vTri[0] * vTri[0] + vTri[1] * vTri[1]
			== vTri[2] * vTri[2]) {
			vRet.push_back("right");
		}
		else {
			vRet.push_back("wrong");
		}
	}
	for (const auto& s : vRet) cout << s << '\n';

	return 0;
}

