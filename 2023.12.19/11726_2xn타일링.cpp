#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nNum;
	cin >> nNum;
	
	// 2x1 = 1  2x2 = 2  2x3 = 3 2x4 = 5 2x5 = 8? 6 = 13 7 = 21 8 = 34 9 = 55

	vector<int> vDp(1001);
	vDp[1] = 1;
	vDp[2] = 2;

	for (int i = 3; i <= 1000; i++) {
		vDp[i] = (vDp[i - 1] + vDp[i - 2]) % 10007;
	}

	cout << vDp[nNum];

	return 0;
}