#include <bits/stdc++.h>

using namespace std;

int main() {
	int nYear;
	vector<int> vSound(8), vTemp(8);

	for (int i = 0; i < 8; i++) {
		cin >> vSound[i];
		vTemp[i] = vSound[i];
	}

	sort(vTemp.begin(), vTemp.end());
	if (vTemp == vSound) {
		cout << "ascending";
	}
	else {
		sort(vTemp.begin(), vTemp.end(),
			[](int a1, int a2) { return a1 > a2; });
		if (vTemp == vSound) {
			cout << "descending";
		}
		else {
			cout << "mixed";
		}
	}
	return 0;
}